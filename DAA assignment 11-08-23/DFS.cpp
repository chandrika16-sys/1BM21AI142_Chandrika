#include <iostream>
using namespace std;

const int MAX_NODES = 100; // Maximum number of nodes

void DFS(int graph[MAX_NODES][MAX_NODES], int numNodes, int node, bool visited[MAX_NODES]) {
    visited[node] = true;
    cout << node << " ";

    for (int neighbor = 0; neighbor < numNodes; ++neighbor) {
        if (graph[node][neighbor] && !visited[neighbor]) {
            DFS(graph, numNodes, neighbor, visited);
        }
    }
}

bool isConnected(int graph[MAX_NODES][MAX_NODES], int numNodes) {
    bool visited[MAX_NODES] = {false};

    DFS(graph, numNodes, 0, visited);

    for (int i = 0; i < numNodes; ++i) {
        if (!visited[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    int numNodes, numEdges;
    cout << "Enter the number of nodes and edges: ";
    cin >> numNodes >> numEdges;

    int graph[MAX_NODES][MAX_NODES] = {{0}};

    cout << "Enter the edges (format: u v): " << endl;
    for (int i = 0; i < numEdges; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1; // Assuming undirected graph
    }

    int startNode;
    cout << "Enter the starting node for DFS: ";
    cin >> startNode;

    cout << "DFS traversal from node " << startNode << ": ";
    bool visited[MAX_NODES] = {false};
    DFS(graph, numNodes, startNode, visited);
    cout << endl;

    bool connected = isConnected(graph, numNodes);
    if (connected) {
        cout << "The graph is connected." << endl;
    } else {
        cout << "The graph is not connected." << endl;
    }

    return 0;
}
