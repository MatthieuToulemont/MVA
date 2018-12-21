from keras.models import Sequential
from keras.layers import Dense, ReLU, Softmax, MaxPool2D, Conv2D, Flatten, Dropout, BatchNormalization
from keras.initializers import glorot_normal


def cnn_reg_dp():
    model = Sequential()
    model.add(Conv2D(32, kernel_size=(3,3), strides=1, activation='relu', kernel_initializer=glorot_normal()))
    model.add(MaxPool2D(pool_size=(2,2), strides=(2,2)))
    model.add(Dropout(0.25))
    model.add(Conv2D(64, kernel_size=(3, 3), strides=1, activation='relu', kernel_initializer=glorot_normal()))
    model.add(MaxPool2D(pool_size=(2, 2), strides=(2, 2)))
    model.add(Dropout(0.25))
    model.add(Conv2D(128, kernel_size=(3, 3), strides=1, activation='relu', kernel_initializer=glorot_normal()))
    model.add(MaxPool2D(pool_size=(2, 2), strides=(2, 2)))
    model.add(Dropout(0.25))
    model.add(Flatten())
    model.add(Dense(256, activation='relu',kernel_initializer=glorot_normal()))
    model.add(Dense(64, activation='relu', kernel_initializer=glorot_normal()))
    model.add(Dense(6))
    model.compile(loss="mean_squared_error", optimizer="adam")
    return model
