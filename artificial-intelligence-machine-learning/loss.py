import matplotlib.pyplot as plt
import numpy as np
from sklearn.datasets import load_iris
from sklearn.linear_model import LinearRegression
from sklearn.metrics import mean_squared_error
from sklearn.model_selection import train_test_split
def loss(y_true, y_pred, model):
       _01_loss = np.sum(np.abs(y_true - y_pred) > 0.1)
       lasso_loss = np.sum(np.abs(y_true - y_pred))
       ridge_loss = np.sum(np.abs(y_true - y_pred) ** 2)
       mse_loss = mean_squared_error(y_true, y_pred)
       print(f"Number of predictions:         {len(y_pred)}")
       print(f"0-1 Loss:                      {_01_loss:.2f}")
       print(f"L1 (Lasso) Loss:               {lasso_loss:.2f}")
       print(f"L2 (Ridge) Loss:               {ridge_loss:.2f}")
       print(f"Mean Squared Error (MSE) Loss: {mse_loss:.2f}\n")
def linear_loss():
       iris = load_iris()
       x = iris.data[:, 0].reshape(-1, 1)
       y = iris.data[:, 1]
       x_train, x_test, y_train, y_test = train_test_split(x, y, test_size = 0.16, random_state = 1)
       model = LinearRegression()
       model.fit(x_train, y_train)
       y_pred = model.predict(x_test)
       loss(y_test, y_pred, model)
       plt.scatter(x_test, y_test, color = "blue", label = "Actual")
       plt.scatter(x_test, y_pred, color = "red", label = "Predicted")
       plt.plot(x_test, y_pred, color = "green", linewidth = 1, label = "Regression Line")
       for i in range(len(x_test)):
               plt.plot([x_test[i], x_test[i]], [y_test[i], y_pred[i]], color = "gray", linestyle = "--", linewidth = 0.5)
       plt.title("Linear Regression with Loss Functions")
       plt.xlabel("Feature 1")
       plt.ylabel("Feature 2")
       plt.legend()
       plt.show()
linear_loss()
