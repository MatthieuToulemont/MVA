import numpy as np
from keras.callbacks import ModelCheckpoint
from keras import models

def oneHot(Y):
    H = np.zeros((Y.shape[0], len(set(Y))))
    for i in range(Y.shape[0]):
        H[i, int(Y[i])]=1
    return H

def eval_model(model, train,test):
    print("Training set : " + str(model.evaluate(train[0], train[1])))
    print("Testing set : " + str(model.evaluate(test[0], test[1])))

def makeMCP(name):
    return ModelCheckpoint('{}.hdf5'.format(name), monitor="val_loss",
                      save_best_only=True, save_weights_only=False)
def loadModel(name):
    return models.load_model('{}.hdf5'.format(name))

def sort_by_x(Y):
    Z = np.zeros_like(Y)
    for row in range(Y.shape[0]):
        y = Y[row].reshape(3,2)
        Z[row] = y[y[:,0].argsort(),:].flatten()
    return Z
