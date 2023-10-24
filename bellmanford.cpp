#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

struct Edge {
    int source, destination, weight;
};

void bellmanFord(vector<Edge>& edges, int V, int E, int source) {
    vector<int> distance(V, INF);
    distance[source] = 0;

    // Relax all edges V-1 times
    for (int i = 0; i < V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].source;
            int v = edges[j].destination;
            int w = edges[j].weight;
            if (distance[u] != INF && distance[u] + w < distance[v]) {
                distance[v] = distance[u] + w;
            }
        }
    }

    // Check for negative weight cycles
    for (int i = 0; i < E; i++) {
        int u = edges[i].source;
        int v = edges[i].destination;
        int w = edges[i].weight;
        if (distance[u] != INF && distance[u] + w < distance[v]) {
            cout << "Graph contains a negative weight cycle." << endl;
            return;
        }
    }

    // Print the shortest distances from the source vertex
    cout << "Shortest distances from the source vertex (vertex " << source << "):" << endl;
    for (int i = 0; i < V; i++) {
        cout << "Vertex " << i << ": " << distance[i] << endl;
    }
}

int main() {
    int V, E;
    cout << "Enter the number of vertices (V) and edges (E): ";
    cin >> V >> E;

    vector<Edge> edges(E);

    cout << "Enter the source, destination, and weight of each edge:" << endl;
    for (int i = 0; i < E; i++) {
        cin >> edges[i].source >> edges[i].destination >> edges[i].weight;
    }

    int source;
    cout << "Enter the source vertex: ";
    cin >> source;

    clock_t startTime = clock();
    bellmanFord(edges, V, E, source);
    clock_t endTime = clock();

    double timeElapsed = double(endTime - startTime) / CLOCKS_PER_SEC;
    cout << "Time taken by Bellman-Ford algorithm: " << timeElapsed << " seconds" << endl;
    cout << "Expected time complexity: O(V * E)" << endl;

    return 0;
}
