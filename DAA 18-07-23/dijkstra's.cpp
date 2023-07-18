#include <iostream>
#include <limits>
#include <queue>

#define MAX_VERTICES 100

class Graph {
private:
    int numVertices;
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];

public:
    Graph(int numVertices);
    void addEdge(int src, int dest, int weight);
    void dijkstraMST(int src);

private:
    int findMinDistance(const int* distance, const bool* mstSet);
};

Graph::Graph(int numVertices) {
    this->numVertices = numVertices;

    // Initialize adjacency matrix
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j)
            adjacencyMatrix[i][j] = 0;  // Initialize all edges as 0
    }
}

void Graph::addEdge(int src, int dest, int weight) {
    adjacencyMatrix[src][dest] = weight;
    adjacencyMatrix[dest][src] = weight;
}

int Graph::findMinDistance(const int* distance, const bool* mstSet) {
    int min = std::numeric_limits<int>::max();
    int minIndex;

    for (int v = 0; v < numVertices; ++v) {
        if (!mstSet[v] && distance[v] < min) {
            min = distance[v];
            minIndex = v;
        }
    }

    return minIndex;
}

void Graph::dijkstraMST(int src) {
    int distance[MAX_VERTICES];
    bool mstSet[MAX_VERTICES];

    // Initialize distance array and MST set
    for (int i = 0; i < numVertices; ++i) {
        distance[i] = std::numeric_limits<int>::max();
        mstSet[i] = false;
    }

    // Distance of source vertex from itself is always 0
    distance[src] = 0;

    // Create a priority queue (min heap) to store vertices with their distances
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;

    // Insert source vertex into the priority queue
    pq.push(std::make_pair(0, src));

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        mstSet[u] = true;

        for (int v = 0; v < numVertices; ++v) {
            if (!mstSet[v] && adjacencyMatrix[u][v] && distance[u] != std::numeric_limits<int>::max() &&
                distance[u] + adjacencyMatrix[u][v] < distance[v]) {
                distance[v] = distance[u] + adjacencyMatrix[u][v];
                pq.push(std::make_pair(distance[v], v));
            }
        }
    }

    std::cout << "Minimum Spanning Tree (Dijkstra's Algorithm):\n";
    std::cout << "Vertex \tDistance from Source\n";
    for (int i = 0; i < numVertices; ++i) {
        std::cout << i << " \t" << distance[i] << std::endl;
    }
}

int main() {
    int numVertices, numEdges;
    std::cout << "Enter the number of vertices in the graph: ";
    std::cin >> numVertices;
    std::cout << "Enter the number of edges in the graph: ";
    std::cin >> numEdges;

    Graph graph(numVertices);

    std::cout << "Enter the edges (source, destination, weight):\n";
    for (int i = 0; i < numEdges; ++i) {
        int src, dest, weight;
        std::cin >> src >> dest >> weight;
        graph.addEdge(src, dest, weight);
    }

    int srcVertex;
    std::cout << "Enter the source vertex: ";
    std::cin >> srcVertex;

    graph.dijkstraMST(srcVertex);

    return 0;
}

