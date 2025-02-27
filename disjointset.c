#include <stdio.h>

// Function to initialize the disjoint set with parent and rank arrays
void makeSet(int parent[], int rank[], int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i; // Each element is its own parent initially
        rank[i] = 0;   // Rank is initialized to 0
    }
}

// Function to find the representative (root) of a set using path compression
int findParent(int parent[], int component) {
    if (parent[component] != component) {
        parent[component] = findParent(parent, parent[component]); // Path compression
    }
    return parent[component];
}

// Function to perform the union of two sets by rank
void unionSet(int u, int v, int parent[], int rank[]) {
    int rootU = findParent(parent, u);
    int rootV = findParent(parent, v);

    if (rootU != rootV) {
        if (rank[rootU] < rank[rootV]) {
            parent[rootU] = rootV;
        } else if (rank[rootU] > rank[rootV]) {
            parent[rootV] = rootU;
        } else {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
    }
}

// Example usage
int main() {
    int n = 5; // Number of elements
    int parent[n];
    int rank[n];

    // Initialize the disjoint set
    makeSet(parent, rank, n);

    // Perform some union operations
    unionSet(0, 1, parent, rank);
    unionSet(1, 2, parent, rank);
    unionSet(3, 4, parent, rank);

    // Find and display the parent of each element
    for (int i = 0; i < n; i++) {
        printf("Parent of %d: %d\n", i, findParent(parent, i));
    }

    return 0;
}

