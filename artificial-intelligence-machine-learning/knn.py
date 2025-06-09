import matplotlib.pyplot as plt
from sklearn.datasets import load_iris
from sklearn.metrics import accuracy_score
from sklearn.model_selection import train_test_split
from sklearn.neighbors import KNeighborsClassifier
def k_nn_classification(k = 4):
        iris = load_iris()
        x, y = iris.data, iris.target
        x_train, x_test, y_train, y_test = train_test_split(x, y, test_size = 0.16, random_state = 1)
        knn = KNeighborsClassifier(n_neighbors = k)
        knn.fit(x_train, y_train)
        y_pred = knn.predict(x_test)
        accuracy = accuracy_score(y_test, y_pred)
        print(f"Accuracy: {accuracy * 100:.2f}%")
        plt.scatter(x_test[:, 0], x_test[:, 1], c = y_pred)
        plt.xlabel("Feature 1")
        plt.ylabel("Feature 2")
        plt.title("Iris Dataset Visualisation (Predicted)")
        plt.show()
        plt.scatter(x_test[:, 0], x_test[:, 1], c = y_test)
        plt.xlabel("Feature 1")
        plt.ylabel("Feature 2")
        plt.title("Iris Dataset Visualisation (Actual)")
        plt.show()
k_nn_classification()