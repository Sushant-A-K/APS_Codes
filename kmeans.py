from sklearn.cluster import KMeans
import numpy as np
import matplotlib.pyplot as plt

# Generating random data
np.random.seed(0)
X = np.random.rand(100, 2)

# Initialize KMeans
kmeans = KMeans(n_clusters=3)

# Fit KMeans clustering model
kmeans.fit(X)

# Predict the cluster labels
labels = kmeans.labels_

# Get the cluster centers
centers = kmeans.cluster_centers_

# Visualize the data points and centroids
plt.scatter(X[:, 0], X[:, 1], c=labels, cmap='viridis', edgecolor='k')
plt.scatter(centers[:, 0], centers[:, 1], marker='x', color='red', s=200, label='Centroids')
plt.title('KMeans Clustering')
plt.legend()
plt.show()
