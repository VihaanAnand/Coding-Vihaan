import matplotlib.pyplot as plt
import numpy as np
from sklearn.datasets import load_iris
from sklearn.linear_model import LinearRegression
from sklearn.metrics import mean_squared_error
from sklearn.preprocessing import PolynomialFeatures
from sklearn.model_selection import train_test_split
def loss(y_true, y_pred):
        _01_loss = np.sum(np.abs(y_true - y_pred) > 0.1)
        lasso_loss = np.sum(np.abs(y_true - y_pred))
        ridge_loss = np.sum(np.abs(y_true - y_pred) ** 2)
        mse_loss = mean_squared_error(y_true, y_pred)
        print(f"Number of predictions:         {len(y_pred)}")
        print(f"0-1 Loss:                      {_01_loss:.2f}")
        print(f"L1 (Lasso) Loss:               {lasso_loss:.2f}")
        print(f"L2 (Ridge) Loss:               {ridge_loss:.2f}")
        print(f"Mean Squared Error (MSE) Loss: {mse_loss:.2f}\n")
def overfitting():
        iris = load_iris()
        x = iris.data[:, 0].reshape(-1, 1)
        y = iris.data[:, 1]
        x_train, x_test, y_train, y_test = train_test_split(x, y, test_size = 0.16, random_state = 1)
        model_linear = LinearRegression()
        model_linear.fit(x_train, y_train)
        y_pred_linear = model_linear.predict(x_test)
        poly = PolynomialFeatures(degree = 64)
        x_poly_train = poly.fit_transform(x_train)
        x_poly_test = poly.transform(x_test)
        model_poly = LinearRegression()
        model_poly.fit(x_poly_train, y_train)
        y_pred_poly = model_poly.predict(x_poly_test)
        print("Linear:")
        loss(y_test, y_pred_linear)
        print("\nPolynomial (Overfit):")
        loss(y_test, y_pred_poly)
        print(f"Linear Model Complexity:    {len(model_linear.coef_)} coefficient")
        print(f"Polynomial Model Complexity: {len(model_poly.coef_)} coefficients\n")
        plt.scatter(x_test, y_test, color = "blue", label = "Actual Data")
        plt.plot(x_test, y_pred_linear, color = "green", label = "Linear Model", linewidth = 2)
        x_min, x_max = 4, 8
        y_min, y_max = 2, 4
        mask = (x_test[:, 0] >= x_min) & (x_test[:, 0] <= x_max) & (y_pred_poly >= y_min) & (y_pred_poly <= y_max)
        x_test_restricted = x_test[mask]
        y_pred_poly_restricted = y_pred_poly[mask]
        plt.plot(x_test_restricted, y_pred_poly_restricted, color = "red", label = "Polynomial Model (Overfit)", linewidth = 2)
        plt.title("Linear vs. Overfit Model")
        plt.legend()
        plt.show()
overfitting()