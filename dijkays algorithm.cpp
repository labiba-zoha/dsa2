
#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

// Global variable for adjacency list
vector<vector<pair<int, int>>> adj;

// Function to find the shortest distance of all the vertices from the source vertex S
vector<int> dijkstra(int V, int S)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(V, 1e9); // Initialize distances to infinity

    dist[S] = 0; // Distance to the source is 0
    pq.push({0, S}); // Push the source vertex into the priority queue

    while (!pq.empty())
    {
        int dis = pq.top().first; // Distance to the current node
        int node = pq.top().second; // Current node
        pq.pop();

        for (auto it : adj[node])   // Iterate through all adjacent nodes
        {
            int edgeWeight = it.second; // Weight of the edge
            int adjNode = it.first; // Adjacent node

            // Relaxation step
            if (dis + edgeWeight < dist[adjNode])
            {
                dist[adjNode] = dis + edgeWeight; // Update the distance
                pq.push({dist[adjNode], adjNode}); // Push the updated distance and node into the queue
            }
        }
    }

    return dist; // Return the shortest distances
}

int main()
{
    int v = 9;  // Number of vertices
    int s = 0;  // Source vertex
    adj.resize(v);

    // Graph from the given image
    adj[0].push_back({1, 4});
    adj[0].push_back({7, 8});
    adj[1].push_back({0, 4});
    adj[1].push_back({7, 11});
    adj[1].push_back({2, 8});
    adj[2].push_back({1, 8});
    adj[2].push_back({8, 2});
    adj[2].push_back({3, 7});
    adj[2].push_back({5, 4});
    adj[3].push_back({2, 7});
     adj[3].push_back({4, 9});
    adj[3].push_back({5, 14});
    adj[4].push_back({5, 10});
    adj[4].push_back({3, 9});
    adj[5].push_back({6, 2});
    adj[5].push_back({2, 4});
    adj[5].push_back({3, 14});
    adj[5].push_back({4, 10});
    adj[6].push_back({7, 1});
    adj[6].push_back({8, 6});
    adj[6].push_back({5, 2});
    adj[7].push_back({8, 7});
    adj[7].push_back({0, 8});
    adj[7].push_back({6, 1});
     adj[7].push_back({1, 11});
    adj[8].push_back({2, 2});
    adj[8].push_back({6, 6});
    adj[8].push_back({7, 7});


    // Call the dijkstra function
    vector<int> distances = dijkstra(v, s);

    // Print the shortest distances
    cout << "Shortest distances from source vertex " << s << ":\n";
    for (int i = 0; i < distances.size(); i++)
    {
        cout << "Vertex " << i << ": " << distances[i] << "\n";
    }

    return 0;
}
