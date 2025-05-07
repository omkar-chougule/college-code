import tensorflow as tf
import tensorflow_datasets as tfds




# Set a shorter path for TensorFlow Datasets
import os
os.environ['TFDS_DATA_DIR'] = 'C:/tensorflow_datasets'

# Load the Plant Village dataset
(ds_train, ds_test), ds_info = tfds.load(
    'plant_village',
    split=['train[:80%]', 'train[80%:]'],
    shuffle_files=True,
    as_supervised=True,
    with_info=True,
)

def preprocess(image, label):
    image = tf.image.resize(image, (128, 128))
    image = tf.cast(image, tf.float32) / 255.0  # Normalize to [0,1]
    return image, label

ds_train = ds_train.map(preprocess).batch(32).prefetch(tf.data.AUTOTUNE)
ds_test = ds_test.map(preprocess).batch(32).prefetch(tf.data.AUTOTUNE)

model = tf.keras.Sequential([
    tf.keras.layers.Conv2D(32, (3,3), activation='relu', input_shape=(128, 128, 3)),
    tf.keras.layers.MaxPooling2D(2, 2),
    tf.keras.layers.Conv2D(64, (3,3), activation='relu'),
    tf.keras.layers.MaxPooling2D(2,2),
    tf.keras.layers.Flatten(),
    tf.keras.layers.Dense(128, activation='relu'),
    tf.keras.layers.Dense(ds_info.features['label'].num_classes, activation='softmax')
])

model.compile(optimizer='adam',
              loss='sparse_categorical_crossentropy',
              metrics=['accuracy'])




# Train the model
model.fit(ds_train, epochs=5, validation_data=ds_test)




# Evaluate the model
loss, acc = model.evaluate(ds_test)
print(f"Test Loss: {loss:.2f}")
print(f"Test Accuracy: {acc:.2f}")