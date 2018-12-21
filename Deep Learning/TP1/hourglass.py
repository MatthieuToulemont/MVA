from keras.models import Sequential
from keras.layers import MaxPool2D, Conv2D, UpSampling2D
from keras.initializers import glorot_normal


def hourglass_model():
    # Encoding
    model = Sequential()
    model.add(Conv2D(32, kernel_size=(3, 3), padding="same", activation='relu', kernel_initializer=glorot_normal()))
    model.add(MaxPool2D(pool_size=(2, 2), strides=(2, 2)))
    model.add(Conv2D(64, kernel_size=(3, 3), padding="same", activation='relu', kernel_initializer=glorot_normal()))
    model.add(MaxPool2D(pool_size=(2, 2), strides=(2, 2)))
    # Decoding
    model.add(Conv2D(64, kernel_size=(3, 3), padding="same", activation='relu', kernel_initializer=glorot_normal()))
    model.add(UpSampling2D(size=(2, 2)))
    model.add(Conv2D(32, kernel_size=(3, 3), padding="same", activation='relu', kernel_initializer=glorot_normal()))
    model.add(UpSampling2D(size=(2, 2)))
    model.add(Conv2D(1, kernel_size=(3, 3), padding="same", activation='sigmoid', kernel_initializer=glorot_normal()))

    model.compile(loss="binary_crossentropy", optimizer="adadelta")
    return model