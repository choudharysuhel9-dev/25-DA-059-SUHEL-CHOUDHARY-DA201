//EXPERIMENT 4
// NAME = SUHEL CHOUDHARY
//ROLL NO. =  25/DA/059
#include <iostream>
#include <vector>
using namespace std;

class Graph {
    int V;                      // Number of vertices
    vector<vector<int>> adj;    // Adjacency list

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    // Add an undirected edge between u and v
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // DFS utility function to visit all nodes in one component
    void DFSUtil(int node, vector<bool>& visited, vector<int>& component) {
        visited[node] = true;
        component.push_back(node);

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                DFSUtil(neighbor, visited, component);
            }
        }
    }

    // Find and print all connected components
    void findConnectedComponents() {
        vector<bool> visited(V, false);
        int componentCount = 0;

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                vector<int> component;
                DFSUtil(i, visited, component);

                componentCount++;
                cout << "Component " << componentCount << ": ";
                for (int node : component) {
                    cout << node << " ";
                }
                cout << endl;
            }
        }

        cout << "\nTotal number of connected components: " << componentCount << endl;
    }
};

int main() {
    // Example graph with 10 vertices (0 to 9)
    Graph g(10);

    // Component 1: 0-1-2-3
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);

    // Component 2: 4-5
    g.addEdge(4, 5);

    // Component 3: 6-7-8
    g.addEdge(6, 7);
    g.addEdge(7, 8);

    // Component 4: 9 (isolated vertex)

    g.findConnectedComponents();

    return 0;
}