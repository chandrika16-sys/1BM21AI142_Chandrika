#include <iostream>
#include <queue>
using namespace std;

const int MAX_NODES = 100; // Maximum number of nodes

void BFS(int graph[MAX_NODES][MAX_NODES], int numNodes, int start) {
    bool visited[MAX_NODES] = {false};
    queue<int> q;

    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int neighbor = 0; neighbor < numNodes; ++neighbor) {
            if (graph[node][neighbor] && !visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
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
    }

    int startNode;
    cout << "Enter the starting node for BFS: ";
    cin >> startNode;

    cout << "BFS traversal from node " << startNode << ": ";
    BFS(graph, numNodes, startNode);
    cout << endl;

    return 0;
}
