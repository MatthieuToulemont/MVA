from keras.models import Sequential
from keras.layers import Dense, ReLU, Softmax, MaxPool2D, Conv2D, Flatten, Dropout, BatchNormalization
from keras.initializers import glorot_normal



def base_model():
    model = Sequential()
    model.add(Dense(3, input_dim=5184, activation="softmax"))
    model.compile(loss="categorical_crossentropy", optimizer="adam",metrics=["accuracy"])
    return model
def cnn_model_Q1():
    model = Sequential()
    model.add(Conv2D(32, kernel_size=(5, 5), strides=1, activation='relu'))
    model.add(MaxPool2D(pool_size=(2, 2), strides=2))
    model.add(Conv2D(64, kernel_size=(5, 5), strides=1, activation='relu'))
    model.add(MaxPool2D(pool_size=(2, 2), strides=2))
    model.add(Flatten())
    model.add(Dense(20, activation='relu'))
    model.add(Dense(3, activation='softmax'))
    model.compile(loss="categorical_crossentropy", optimizer="adam", metrics=['accuracy'])
    return model
def cnn_model_bn_Q1():
    model = Sequential()
    model.add(Conv2D(32, kernel_size=(5,5), strides = 1, activation = 'relu', kernel_initializer=glorot_normal()))
    model.add(BatchNormalization())
    model.add(MaxPool2D(pool_size = (2,2), strides = 2))
    model.add(Conv2D(64, kernel_size=(5,5), strides = 1, activation = 'relu', kernel_initializer=glorot_normal()))
    model.add(BatchNormalization())
    model.add(MaxPool2D(pool_size = (2,2), strides = 2))
    model.add(Flatten())
    model.add(Dense(20, activation = 'relu', kernel_initializer=glorot_normal()))
    model.add(BatchNormalization())
    model.add(Dense(3, activation = 'softmax', kernel_initializer=glorot_normal()))
    model.compile(loss="categorical_crossentropy", optimizer="adam", metrics=['accuracy'])
    return model