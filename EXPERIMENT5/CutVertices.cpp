//EXPWRIMENT 5
//NAME = SUHEL CHOUDHARY
//ROLL NO. = 25/DA/059
//Write a program to identify the Cut Vertices (Articulation Points) in a graph.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;
    vector<int> disc, low;
    vector<bool> visited, articulation;
    int timer;

    void DFS(int u, int parent) {
        visited[u] = true;

        disc[u] = low[u] = timer++;
        int children = 0;

        for (int v : adj[u]) {

            // Ignore the edge to parent
            if (v == parent)
                continue;

            // If v is already visited, it is a back edge
            if (visited[v]) {
                low[u] = min(low[u], disc[v]);
            }
            else {
                children++;

                DFS(v, u);

                // Update low value
                low[u] = min(low[u], low[v]);

                // Check articulation point condition
                if (parent != -1 && low[v] >= disc[u]) {
                    articulation[u] = true;
                }
            }
        }

        // Root of DFS tree with more than one child
        if (parent == -1 && children > 1) {
            articulation[u] = true;
        }
    }

public:
    Graph(int V) {
        this->V = V;

        adj.resize(V);
        disc.assign(V, -1);
        low.assign(V, -1);
        visited.assign(V, false);
        articulation.assign(V, false);

        timer = 0;
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void findArticulationPoints() {

        // Graph may be disconnected
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                DFS(i, -1);
            }
        }

        cout << "\nArticulation Points (Cut Vertices): ";

        bool found = false;

        for (int i = 0; i < V; i++) {
            if (articulation[i]) {
                cout << i << " ";
                found = true;
            }
        }

        if (!found) {
            cout << "None";
        }

        cout << endl;
    }
};

int main() {

    int V, E;

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    Graph g(V);

    cout << "Enter edges (u v):\n";

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;

        g.addEdge(u, v);
    }

    g.findArticulationPoints();

    return 0;
}