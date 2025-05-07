import numpy as np
import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler,LabelEncoder
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Dense,Input
from tensorflow.keras.utils import to_categorical
from sklearn.metrics import classification_report
import matplotlib.pyplot as plt

df = pd.read_csv("https://archive.ics.uci.edu/ml/machine-learning-databases/letter-recognition/letter-recognition.data", header=None)

df.columns=['letter'] + [f'feat{i}' for i in range (1,17)]

le=LabelEncoder()
yint=le.fit_transform(df['letter'])
y=to_categorical(yint)

x = StandardScaler().fit_transform(df.drop('letter' , axis=1))

x_t,x_test,y_t,y_test=train_test_split(x,y,test_size=0.2)

model=Sequential([
    Input(shape=(16,)),
    Dense(64, activation='relu'),
    Dense(32, activation='relu'),
    Dense(26, activation='softmax')
])

model.compile(optimizer='adam', loss='categorical_crossentropy', metrics=['accuracy'])
hist=model.fit(x_t,y_t,epochs=10, validation_split=0.2)

y_pr=np.argmax(model.predict(x_test),axis=1)
ytr=np.argmax(y_test,axis=1)

print("classification report \n")
print(classification_report(ytr,y_pr,target_names=le.inverse_transform(range(26))))

plt.figure(figsize=(10,4))
plt.subplot(1,2,1)
plt.plot(hist.history['accuracy'], label='Train Acc')
plt.plot(hist.history['val_accuracy'], label='Val Acc')
plt.title('Accuracy')
plt.legend()

plt.subplot(1,2,2)
plt.plot(hist.history['loss'], label='Train Loss')
plt.plot(hist.history['val_loss'], label='Val Loss')
plt.title('Loss')
plt.legend()
plt.tight_layout()
plt.show()