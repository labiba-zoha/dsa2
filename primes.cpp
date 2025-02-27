#include<bits/stdc++.h>
using namespace std;
#define V 7// Number of vertices

int selectminvertex(vector<int>& nodeweight, vector<bool>& setMst) {
    // Will return the node with minimum nodeweight that is not yet in MST
    int minimum = INT_MAX;
    int vertex;
    for(int i = 0; i < V; i++) {
        if(setMst[i] == false && nodeweight[i] < minimum) {
            vertex = i;
            minimum = nodeweight[i];
        }
    }
    return vertex;
}

void findmst(vector <vector<int>> &graph) {
    int parent[V];
    vector<int> nodeweight(V, INT_MAX);
    vector<bool> setMst(V, false);
    parent[0] = -1; // Source is 0
    nodeweight[0] = 0; // Weight of source is 0

    for(int i = 0; i < V-1; i++) {
        int u = selectminvertex(nodeweight, setMst);
        setMst[u] = true; // Include u in MST

        for(int j = 0; j < V; j++) {
            // Find the minimum adjacent node to u
            if(graph[u][j] != 0 && setMst[j] == false && graph[u][j] < nodeweight[j]) {
                nodeweight[j] = graph[u][j];
                parent[j] = u;
            }
        }
    }

    // Print the MST and its total cost
    int totalCost = 0;
    cout << "Edges in MST:\n";
    for(int i = 1; i < V; i++) {
        cout << "Edge: " << parent[i] << " - " << i << " with weight " << graph[i][parent[i]] << endl;
        totalCost += graph[i][parent[i]];
    }

    cout << "Minimum cost of MST: " << totalCost << endl;
}

int main() {
    // Adjacency matrix representation of the graph
   vector<vector<int>> graph = {
    {0, 6, 5, 2, 0, 0, 0},  // Edges from vertex 'a' (0)
    {6, 0, 0, 6, 5, 4, 0},  // Edges from vertex 'b' (1)
    {5, 0, 0, 4, 4, 0, 4},  // Edges from vertex 'c' (2)
    {2, 6, 4, 0, 4, 0, 4},  // Edges from vertex 'd' (3)
    {0, 0, 4, 6, 0, 2, 0},  // Edges from vertex 'e' (4)
    {0, 4, 0, 3, 2, 0, 0},  // Edges from vertex 'f' (5)
    {0, 0, 4, 4, 0, 0, 0}   // Edges from vertex 'g' (6)
};


    findmst(graph); // Find and print the MST

    return 0;
}
