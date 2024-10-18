import matplotlib.pyplot as plt
from sklearn.datasets import load_iris
from sklearn.linear_model import LinearRegression
from sklearn.model_selection import train_test_split
from sklearn.metrics import mean_squared_error, r2_score
def linear_regression():
       iris = load_iris()
       x = iris.data[:, 0].reshape(-1, 1)
       y = iris.data[:, 1]
       x_train, x_test, y_train, y_test = train_test_split(x, y, test_size = 0.16, random_state = 1)
       model = LinearRegression()
       model.fit(x_train, y_train)
       y_pred = model.predict(x_test)
       plt.scatter(x_test, y_test, color = "blue", label = "Actual")
       plt.scatter(x_test, y_pred, color = "red", label = "Predicted")
       plt.plot(x_test, y_pred, color = "green", linewidth = 1, label = "Regression Line")
       plt.title("Linear Regression on Iris Dataset")
       plt.xlabel("Feature 1")
       plt.ylabel("Feature 2")
       plt.legend()
       plt.show()
linear_regression()
