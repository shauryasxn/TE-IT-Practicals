#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int src, dest, weight;
};

void bellmanFord(Edge edges[], int V, int E, int source) {

    vector <int> distance (V, INT_MAX);
    distance[source] = 0;
    for (int i = 0; i <= V ; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].src;
            int v = edges[j].dest;
            int w = edges[j].weight;
            if (distance[u] != INT_MAX && distance[u] + w < distance[v]) {
                distance[v] = distance[u] + w;
            }
        }
    }
    for (int i = 0; i < E; i++) {
        int u = edges[i].src;
        int v = edges[i].dest;
        int w = edges[i].weight;
        if (distance[u] != INT_MAX && distance[u] + w < distance[v]) {
            cout << "Graph contains negative-weight cycle!" << endl;
            return;
        }
    }
    cout << "Vertex\tDistance from Source" << endl;
    for (int i = 0; i < V; i++) {
        cout << i << "\t" << distance[i] << endl;
    }
}

int main() {
    int V, E;
    cout << "Enter Number of Vertices & Edges (separated by space): " << endl;
    cin >> V >> E;
    Edge edges[E];
    cout << "Enter Source, Destination & Weight (separated by space): " << endl;
    for (int i = 0; i < E; i++) {
        cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
    }
    int source;
    cout << "Enter Source: ";
    cin >> source;
    bellmanFord(edges, V, E, source);
    return 0;
}
