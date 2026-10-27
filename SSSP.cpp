
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Edge {
    int u, v, weight;
};

void bellmanFord(int V, int E, vector<Edge>& edges, int source) {
    vector<int> dist(V, INT_MAX);
    dist[source] = 0;

    // Relax all edges V-1 times
    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].weight;

            if (dist[u] != INT_MAX &&
                dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Check for a negative-weight cycle
    for (int j = 0; j < E; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].weight;

        if (dist[u] != INT_MAX &&
            dist[u] + w < dist[v]) {
            cout << "Negative-weight cycle detected!\n";
            return;
        }
    }

    // Print shortest distances
    cout << "Vertex\tDistance from Source\n";
    for (int i = 0; i < V; i++) {
        cout << i << "\t";
        if (dist[i] == INT_MAX)
            cout << "INF";
        else
            cout << dist[i];
        cout << "\n";
    }
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<Edge> edges(E);

    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < E; i++) {
        cin >> edges[i].u
            >> edges[i].v
            >> edges[i].weight;
    }

    int source;
    cout << "Enter source vertex: ";
    cin >> source;

    bellmanFord(V, E, edges, source);

    return 0;
}
