
#include <stdio.h>
#include <stdlib.h>

int comparator(const void *p1, const void *p2) {
    const int (*x)[3] = p1;
    const int (*y)[3] = p2;
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

void unionSet(int u, int v, int parent[], int rank[], int n) {
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

void kruskalAlgo(int n, int edge[][3], int e) {
    qsort(edge, e, sizeof(edge[0]), comparator);

    int parent[n];
    int rank[n];
    makeSet(parent, rank, n);

    int minCost = 0;
    for (int i = 0; i < e; i++) {
        int srcRoot = findParent(parent, edge[i][0]);
        int dest = edge[i][1];

        if (srcRoot != dest) {  // Directed cycle check
            printf("%d -> %d\n", edge[i][0], edge[i][1]);
            unionSet(srcRoot, dest, parent, rank, n);
            minCost += edge[i][2];
        }
    }
    printf("Minimum Cost Directed Spanning Tree: %d\n", minCost);
}

int main() {
    int edge[5][3] = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    int n = 4; // Number of vertices
    int e = 5; // Number of edges

    kruskalAlgo(n, edge, e);

    return 0;
}
