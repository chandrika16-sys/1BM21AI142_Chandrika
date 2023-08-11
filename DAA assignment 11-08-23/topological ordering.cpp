#include <iostream>
#include <stack>
using namespace std;

const int MAX_NODES = 100; // Maximum number of nodes

void DFS(int node, bool visited[], int graph[MAX_NODES][MAX_NODES], stack<int>& order, int numNodes) {
    visited[node] = true;

    for (int neighbor = 0; neighbor < numNodes; ++neighbor) {
        if (graph[node][neighbor] && !visited[neighbor]) {
            DFS(neighbor, visited, graph, order, numNodes);
        }
    }

    order.push(node);
}

void topologicalSort(int graph[MAX_NODES][MAX_NODES], int numNodes) {
    bool visited[MAX_NODES] = {false};
    stack<int> order;

    for (int i = 0; i < numNodes; ++i) {
        if (!visited[i]) {
            DFS(i, visited, graph, order, numNodes);
        }
    }

    cout << "Topological ordering: ";
    while (!order.empty()) {
        cout << order.top() << " ";
        order.pop();
    }
    cout << endl;
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

    topologicalSort(graph, numNodes);

    return 0;
}
