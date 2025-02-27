#include <stdio.h>
#include <stdlib.h>

int comparator(const void *p1, const void *p2) {
    const int(*x)[3] = p1; // Declaring an array of 3 integers
    const int(*y)[3] = p2;
    return (*x)[2] - (*y)[2];
}

void makeSet(int parent[], int rank[], int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
}

int findParent(int parent[], int component) {
    if (parent[component] == component)
        return component;
    return parent[component] = findParent(parent, parent[component]);
}

void unionSet(int u, int v, int parent[], int rank[]) {
    u = findParent(parent, u);
    v = findParent(parent, v);

    if (rank[u] < rank[v]) {
        parent[u] = v;
    } else if (rank[u] > rank[v]) {
        parent[v] = u;
    } else {
        parent[v] = u;
        rank[u]++;
    }
}

void kruskalAlgo(int vertices, int edges[][3], int numEdges) {
    qsort(edges, numEdges, sizeof(edges[0]), comparator);

    int parent[vertices];
    int rank[vertices];
    makeSet(parent, rank, vertices);

    int minCost = 0;
    printf("Edges in the Minimum Spanning Tree:\n");
    for (int i = 0; i < numEdges; i++) {
        int v1 = findParent(parent, edges[i][0]);
        int v2 = findParent(parent, edges[i][1]);
        int wt = edges[i][2];

        if (v1 != v2) {
            printf("%d - %d (Weight: %d)\n", edges[i][0], edges[i][1], wt);
            unionSet(v1, v2, parent, rank);
            minCost += wt;
        }
    }
    printf("Minimum Cost Spanning Tree: %d\n", minCost);
}

int main() {
    int edge[][3] = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    int numEdges = sizeof(edge) / sizeof(edge[0]);
    int numVertices = 4; // Number of vertices in the graph

    kruskalAlgo(numVertices, edge, numEdges);

    return 0;
}
