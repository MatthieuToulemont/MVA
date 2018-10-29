# MVA
This repository contains the work done during the MVA Master in Paris.


## TP1
Given two images we ask the user to select a set of corresponding points on both images. Those points are used to estimate the homography between the images. This homography is later used to stich the image together in a panorama.

## TP2
We use SIFT descriptors and RANSAC to compute the fundamental matrix of a camera given two images. We then enable the user to see the epipolar lines of a given point that he can select.
## TP3
Given two images of the same scene we compute the disparity map by a greedy approach using correlations. Once estimated we use the disparity map to reconstruct a 3D profile of the scene. 
## TP4
Given two images of the same object we compute the disparity map and reconstruct a 3D profile off the object.
