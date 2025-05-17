# ================================================================
#  K-Means Clustering from scratch  (beginner friendly, Colab-ready)
#  Follows the algorithm described in “Lab_Manual_09_Updated_Spring_2024”
#  Department of CSE, Green University of Bangladesh                │
# ================================================================

# ---- 1. Imports -------------------------------------------------
import random                     # for reproducible random numbers
from typing import List, Tuple    # for type hints (optional, improves readability)

import numpy as np                # NumPy handles fast vector maths
import matplotlib.pyplot as plt   # Matplotlib visualises the clusters

# ---- 2. Utility functions --------------------------------------
def euclidean(a: np.ndarray, b: np.ndarray) -> float:
    """
    Compute the Euclidean (ℓ2) distance between two vectors a and b.

    Parameters
    ----------
    a, b : np.ndarray
        1-D arrays of the same length, e.g. [x, y].

    Returns
    -------
    float
        The straight-line distance between a and b.
    """
    return np.sqrt(np.sum((a - b) ** 2))


def manhattan(a: np.ndarray, b: np.ndarray) -> float:
    """
    OPTIONAL: Manhattan (ℓ1) distance – uncomment in KMeans below if you
    want the variant requested in the ‘Lab Exercise’ part of the PDF.
    """
    return np.sum(np.abs(a - b))

# ---- 3. Main K-Means class -------------------------------------
class KMeans:
    """
    Minimal, educational implementation of the classical K-Means algorithm.

    Parameters
    ----------
    k : int
        Number of clusters (K in “K-Means”).
    max_iters : int
        Safety cap on iterations in case convergence takes too long.
    distance_fn : callable
        Function that takes two np.ndarrays and returns a scalar distance.
        Defaults to Euclidean, but you can pass `manhattan` instead.

    Attributes created after calling `fit`
    --------------------------------------
    centroids : np.ndarray         shape = (k, d)
        Current centroid coordinates.
    labels_  : np.ndarray          shape = (n_samples,)
        Cluster index (0 … k-1) assigned to each training point.
    """
    def __init__(self, k: int = 3,
                 max_iters: int = 300,
                 distance_fn = euclidean):
        self.k = k
        self.max_iters = max_iters
        self.distance = distance_fn

    # -------------------------------------------------------------
    def _init_centroids(self, X: np.ndarray) -> None:
        """
        Pick k random points from the dataset to serve as the initial centroids
        (Step 2 in the PDF).
        """
        indices = np.random.choice(len(X), size=self.k, replace=False)
        self.centroids = X[indices]

    # -------------------------------------------------------------
    def _assign_clusters(self, X: np.ndarray) -> np.ndarray:
        """
        Step 3: Assign each point to the nearest centroid.

        Returns
        -------
        labels : np.ndarray  shape = (n_samples,)
            Index of the closest centroid for every sample.
        """
        # Compute distance to every centroid, take the argmin (smallest index)
        distances = np.array([
            [self.distance(x, c) for c in self.centroids]  # distances to all k centroids for one x
            for x in X                                     # loop over every sample
        ])
        return np.argmin(distances, axis=1)

    # -------------------------------------------------------------
    def _update_centroids(self, X: np.ndarray, labels: np.ndarray) -> None:
        """
        Step 4: For each cluster, compute the mean (center of gravity)
        of the points assigned to it, and move the centroid there.
        """
        new_centroids = []
        for j in range(self.k):
            points_in_j = X
            # Guard against [labels == j]empty clusters → keep old centroid
            if len(points_in_j) > 0:
                new_centroids.append(points_in_j.mean(axis=0))
            else:
                new_centroids.append(self.centroids[j])
        self.centroids = np.vstack(new_centroids)

    # -------------------------------------------------------------
    def fit(self, X: np.ndarray) -> None:
        """
        Run the full K-Means loop on dataset X until convergence or
        until `max_iters` is hit.

        After fitting, `self.labels_` and `self.centroids` are populated.
        """
        self._init_centroids(X)

        for _ in range(self.max_iters):
            labels = self._assign_clusters(X)        # Step 3+5
            prev_centroids = self.centroids.copy()   # keep a copy to test convergence
            self._update_centroids(X, labels)        # Step 4

            # Check Step 6: if centroids didn’t move → clustering is final
            if np.allclose(self.centroids, prev_centroids):
                break

        self.labels_ = labels  # store final labels so the user can inspect

    # -------------------------------------------------------------
    def inertia(self, X: np.ndarray) -> float:
        """
        Compute “intra-cluster distance” (sum of squared distances between
        every point and its centroid).  Lower => tighter clusters.
        """
        return np.sum([
            self.distance(x, self.centroids[label])**2
            for x, label in zip(X, self.labels_)
        ])

# ---- 4. Quick demo / playground --------------------------------
def demo(n_points: int = 60,
         k: int = 4,
         random_seed: int = 42) -> None:
    """
    Create a random 2-D dataset and run K-Means, then plot the result.
    """
    np.random.seed(random_seed)
    random.seed(random_seed)

    # Make toy data – four Gaussian blobs by default
    X = np.vstack([
        np.random.randn(n_points // k, 2) * 0.6 + np.array([ 0,  0]),
        np.random.randn(n_points // k, 2) * 0.6 + np.array([ 3,  3]),
        np.random.randn(n_points // k, 2) * 0.6 + np.array([ 0,  4]),
        np.random.randn(n_points // k, 2) * 0.6 + np.array([ 4,  0]),
    ])

    # ----- run K-Means ----- #
    kmeans = KMeans(k=k)
    kmeans.fit(X)

    # ----- visualise ----- #
    plt.figure(figsize=(6, 6))
    for j in range(k):
        pts = X[kmeans.labels_ == j]
        plt.scatter(pts[:, 0], pts[:, 1], label=f"Cluster {j+1}")
    plt.scatter(kmeans.centroids[:, 0], kmeans.centroids[:, 1],
                marker="X", s=200, linewidths=2, edgecolors="black",
                label="Centroids")
    plt.title("K-Means clustering result")
    plt.legend()
    plt.grid(True)
    plt.show()

    # ----- report intra-cluster distance ----- #
    print(f"Total inertia (sum of squared distances): {kmeans.inertia(X):.3f}")

# ---- 5. Run the demo when the cell is executed -----------------
demo(n_points=80, k=4, random_seed=1)
