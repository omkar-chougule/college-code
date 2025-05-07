import pandas as pd
from tensorflow.keras.layers import Dense
from tensorflow.keras import Sequential
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler

boston = pd.read_csv('BostonHousing.csv')
boston.dropna(inplace=True)

X = boston.drop(columns=['medv'])  # Features
y = boston['medv']

# Standardize features
scaler = StandardScaler()
X_scaled = scaler.fit_transform(X)




# Split dataset
X_train, X_test, y_train, y_test = train_test_split(X_scaled, y, test_size=0.2, random_state=42)




# Create a simple Deep Neural Network for Linear Regression
model = Sequential([
    Dense(64, activation='relu', input_shape=(X.shape[1],)),
    Dense(64, activation='relu'),
    Dense(1, activation='linear')  # Output layer for regression (linear activation)
])

model.compile(optimizer='adam', loss='mse', metrics=['mae'])




# Train model
model.fit(X_train, y_train, epochs=100, batch_size=16, validation_split=0.1)
from sklearn.metrics import mean_absolute_error


loss, mae = model.evaluate(X_test, y_test)
print(f"Mean Squared Error on Test Set: {loss:.2f}")
# Predict and calculate MAE
predictions = model.predict(X_test)
mae = mean_absolute_error(y_test, predictions)
print(f"Mean Absolute Error on Test Set: {mae:.2f}")
accuracy = model.evaluate(X_test, y_test)[1]
print(f"Accuracy on Test Set: {accuracy:.2f}")
import numpy as np
import matplotlib.pyplot as plt

idx = np.argsort(y_test.values) # Get indices based on values, not index
y_true_sorted = y_test.values[idx] # Access values directly using .values
y_pred_sorted = predictions[idx]

# 10) Plot Actual Prices
plt.figure(figsize=(10, 5))
plt.plot(y_true_sorted, label='Actual', color='blue', linewidth=2)
plt.xlabel("Sample Index")
plt.ylabel("House Price")
plt.title("Actual Boston Housing Prices")
plt.legend()
plt.show()

# 11) Plot Predicted Prices
plt.figure(figsize=(10, 5))
plt.plot(y_pred_sorted, label='Predicted', color='orange', linewidth=2)
plt.xlabel("Sample Index")
plt.ylabel("House Price")
plt.title("Predicted Boston Housing Prices")
plt.legend()
plt.show()