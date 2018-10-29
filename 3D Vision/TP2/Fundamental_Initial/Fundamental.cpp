// Imagine++ project
// Project:  Fundamental
// Author:   Pascal Monasse
// Date:     2013/10/08

#include "./Imagine/Features.h"
#include <Imagine/Graphics.h>
#include <Imagine/LinAlg.h>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace Imagine;
using namespace std;

static const float BETA = 0.01f; // Probability of failure

struct Match {
    float x1, y1, x2, y2;
};

// Display SIFT points and fill vector of point correspondences
void algoSIFT(Image<Color,2> I1, Image<Color,2> I2,
              vector<Match>& matches) {
    // Find interest points
    SIFTDetector D;
    D.setFirstOctave(-1);
    Array<SIFTDetector::Feature> feats1 = D.run(I1);
    drawFeatures(feats1, Coords<2>(0,0));
    cout << "Im1: " << feats1.size() << flush;
    Array<SIFTDetector::Feature> feats2 = D.run(I2);
    drawFeatures(feats2, Coords<2>(I1.width(),0));
    cout << " Im2: " << feats2.size() << flush;

    const double MAX_DISTANCE = 100.0*100.0;
    for(size_t i=0; i < feats1.size(); i++) {
        SIFTDetector::Feature f1=feats1[i];
        for(size_t j=0; j < feats2.size(); j++) {
            double d = squaredDist(f1.desc, feats2[j].desc);
            if(d < MAX_DISTANCE) {
                Match m;
                m.x1 = f1.pos.x();
                m.y1 = f1.pos.y();
                m.x2 = feats2[j].pos.x();
                m.y2 = feats2[j].pos.y();
                matches.push_back(m);
            }
        }
    }
}

vector<Match> randomSample(vector<Match>& matches, int NumberOfMatches){
    vector<Match> M;
    int m_size = matches.size();
    if(NumberOfMatches < m_size){
        vector<int> seen;
        while(M.size() < NumberOfMatches){
            int id;
            id = rand()%m_size;
            if(seen.end()==find(seen.begin(), seen.end(), id)){
                seen.push_back(id);
                M.push_back(matches[id]);
            }
        }
    }
    else{
        cout << "There are not enough  matches in the vector you have provided." << endl;
    }

    return M;
}
FMatrix<float,9,9> buildA(vector<Match>& matches, float& normalization){
    FMatrix<float,9,9> A;
    for(int m = 0; m < 8; m++){
        A(m,0)= matches[m].x1*matches[m].x2*normalization*normalization;
        A(m,1)= matches[m].x1*matches[m].y2*normalization*normalization;
        A(m,2)= matches[m].x1*normalization;
        A(m,3)= matches[m].y1*matches[m].x2*normalization*normalization;
        A(m,4)= matches[m].y1*matches[m].y2*normalization*normalization;
        A(m,5)= matches[m].y1*normalization;
        A(m,6)= matches[m].x2*normalization;
        A(m,7)= matches[m].y2*normalization;
        A(m,8)= 1;
    }
    for(int col = 0; col < 9; col ++){
        A(8,col)=0;
    }
    return A;
};

FMatrix<float,3,3> fromAtoF(FMatrix<float,9,9>& A){
    // Compute SVD.
    FVector<float, 9> D;
    FMatrix<float, 9,9> U;
    FMatrix<float, 9,9> V_transpose;
    svd(A,U,D,V_transpose);

    // F is the last singular direction of V. Thus it the last row of V.
    FMatrix<float,3,3> F;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            F(i,j) = V_transpose(8,3*i+j);
        }
    }
    // Correct F such that it is a rank 2 matrix.
    FVector<float,3> F_D;
    FMatrix<float,3,3>F_U;
    FMatrix<float,3,3>F_V_transpose;
    svd(F,F_U,F_D, F_V_transpose);
    F_D[2] = 0; // Rank 2 Correction.
    F = F_U*Diagonal(F_D)*F_V_transpose;

    return F;
};
void normalizationF(FMatrix<float,3,3>&F, float& normalization){
    FVector<float,3> norm;
    norm[0] = normalization;
    norm[1] = normalization;
    norm[2] = 1;
    F = Diagonal(norm)*F*Diagonal(norm);
};

float computeDistanceWithEpipolarLine(Match& match, FMatrix<float,3,3> F){
    FVector<float,3> X1;
    FVector<float,3> X2;
    FVector<float,3> L;
    X1[0] = match.x1;
    X1[1] = match.y1;
    X1[2] = 1;
    X2[0] = match.x2;
    X2[1] = match.y2;
    X2[2] = 1;

    float L_norm;
    float distance;
    L = F*X2;
    L_norm = pow(pow(L[0],2) + pow(L[1],2), 0.5);
    L /= L_norm;
    distance = abs(X1*L);
    return distance;
};

vector<int> findInliers(vector<Match>& matches, FMatrix<float,3,3>& F, const float distMax){
    float currentDist;
    vector<int> inliers;
    for(int i = 0; i < matches.size(); i++){
        currentDist=computeDistanceWithEpipolarLine(matches[i], F);
        if(currentDist < distMax){
            inliers.push_back(i);
        }
    }
    return inliers;
}
void updateNiter(int& N_iter, int m, int n, const float beta){
    int new_Niter;
    if((float)m/(float)n > 0.5){
        new_Niter = round(log(beta)/(log(1-pow((float)m/(float)n,8))));
        if(new_Niter < N_iter){
            N_iter = new_Niter;
        }
    }
}
// RANSAC algorithm to compute F from point matches (8-point algorithm)
// Parameter matches is filtered to keep only inliers as output.
FMatrix<float,3,3> computeF(vector<Match>& matches) {
    const float distMax = 1.5f; // Pixel error for inlier/outlier discrimination
    int Niter=10000; // Adjusted dynamically
    FMatrix<float,3,3> bestF;
    vector<int> bestInliers;
    // --------------- TODO ------------
    int iter = 0;
    int numberOfMatches = 8;
    float normalization = 0.001;
    const float beta = 0.01;

    while(iter<Niter){
        iter+= 1;

        vector<int> inliers;
        vector<Match> randomMatches;
        FMatrix<float,9,9> A;
        FMatrix<float,3,3> F;
        // GET SOME RANDOM SAMPLES.
        randomMatches = randomSample(matches, numberOfMatches);
        // Compute A from samples
        A = buildA(randomMatches, normalization);
        // COMPUTE F STEP.
        F = fromAtoF(A);
        normalizationF(F,normalization);
        // Find Inliers
        inliers = findInliers(matches, F, distMax);
        if (inliers.size() > bestInliers.size()){
            cout << "New best #Inliers : " << inliers.size() << endl;
            bestInliers.clear();
            bestInliers = inliers;
            bestF = F;
            updateNiter(Niter, bestInliers.size(), matches.size(), beta);
        }
        randomMatches.clear();
        inliers.clear();
    }
    cout << "The total number of iteration was : "<< iter << endl;

    // Updating matches with inliers only
    vector<Match> all=matches;
    matches.clear();
    for(size_t i=0; i<bestInliers.size(); i++)
        matches.push_back(all[bestInliers[i]]);
    return bestF;
}

// Expects clicks in one image and show corresponding line in other image.
// Stop at right-click.
void displayEpipolar(Image<Color> I1, Image<Color> I2,
                     const FMatrix<float,3,3>& F) {
    while(true) {
        int x,y;
        if(getMouse(x,y) == 3)
            break;
        // --------------- TODO ------------
        //Find in which Image the user clicked.
        drawCircle(x,y,10,RED);
        if (x < I1.width()){
            FVector<float,3> X;
            FVector<int,2> EpiR1;
            FVector<int,2> EpiR2;
            FVector<float,3> epipolarLine;
            X[0] = x;X[1] = y; X[2] = 1;
            epipolarLine = transpose(F)*X;

            // Pour trouver les Epipoles on résout <e,F^Tx> = 0
            EpiR1[0]=I1.width();EpiR1[1] = (int)((-1)*epipolarLine[2]/epipolarLine[1]);
            EpiR2[0]=2*I1.width(); EpiR2[1]=(int)((-1)*(epipolarLine[2]+epipolarLine[0]*I1.width())/epipolarLine[1]);

            drawLine(EpiR1[0],EpiR1[1],EpiR2[0],EpiR2[1], RED);
        }
        else{
            // The user clicked in the right image
            FVector<float,3> X;
            FVector<int,2> EpiL1;
            FVector<int,2> EpiL2;
            FVector<float,3> epipolarLine;
            X[0] = x - I1.width();X[1] = y; X[2] = 1;
            epipolarLine = F*X;
            // Pour trouver les Epipoles on résout <e,Fx> = 0
            EpiL1[0]=0;EpiL1[1] = (int)((-1)*epipolarLine[2]/epipolarLine[1]);
            EpiL2[0]=I1.width(); EpiL2[1]=int((-1)*(epipolarLine[2]+epipolarLine[0]*I1.width())/epipolarLine[1]);
            drawLine(EpiL1[0],EpiL1[1],EpiL2[0],EpiL2[1], RED);

        }
    }
}

int main(int argc, char* argv[])
{
    srand((unsigned int)time(0));

    const char* s1 = argc>1? argv[1]: srcPath("im1.jpg");
    const char* s2 = argc>2? argv[2]: srcPath("im2.jpg");

    // Load and display images
    Image<Color,2> I1, I2;
    if( ! load(I1, s1) ||
        ! load(I2, s2) ) {
        cerr<< "Unable to load images" << endl;
        return 1;
    }
    int w = I1.width();
    openWindow(2*w, I1.height());
    display(I1,0,0);
    display(I2,w,0);

    vector<Match> matches;
    algoSIFT(I1, I2, matches);
    cout << " matches: " << matches.size() << endl;
    click();

    cout << "Compute First approximation of F using all the matches" << endl;
    FMatrix<float,3,3> F = computeF(matches);
    cout << "First approximation F="<< endl << F;





    // Redisplay with matches
    display(I1,0,0);
    display(I2,w,0);
    for(size_t i=0; i<matches.size(); i++) {
        Color c(rand()%256,rand()%256,rand()%256);
        fillCircle(matches[i].x1+0, matches[i].y1, 2, c);
        fillCircle(matches[i].x2+w, matches[i].y2, 2, c);        
    }
    click();

    // Redisplay without SIFT points
    display(I1,0,0);
    display(I2,w,0);
    displayEpipolar(I1, I2, F);

    endGraphics();
    return 0;
}
