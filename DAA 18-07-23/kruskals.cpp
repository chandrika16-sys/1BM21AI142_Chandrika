#include <iostream>
#include <queue>
#include <algorithm>

const int MAX_VERTICES = 100;
const int MAX_EDGES = 1000;

class Graph {
    int vertices;
    int edges;
    std::pair<int, std::pair<int, int>> edgeList[MAX_EDGES];

public:
    Graph(int v, int e) : vertices(v), edges(e) {}

    void addEdge(int src, int dest, int weight, int index) {
        edgeList[index] = {weight, {src, dest}};
    }

    int findParent(int parent[], int vertex) {
        if (parent[vertex] != vertex) {
            parent[vertex] = findParent(parent, parent[vertex]);
        }
        return parent[vertex];
    }

    void unionSets(int parent[], int x, int y) {
        int xParent = findParent(parent, x);
        int yParent = findParent(parent, y);
        parent[xParent] = yParent;
    }

    void kruskalMST() {
        std::sort(edgeList, edgeList + edges);

        int parent[MAX_VERTICES];
        for (int i = 0; i < vertices; ++i) {
            parent[i] = i;
        }

        int mstEdges = 0;
        std::cout << "Edge\tWeight\n";
        for (int i = 0; i < edges; ++i) {
            int src = edgeList[i].second.first;
            int dest = edgeList[i].second.second;
            int weight = edgeList[i].first;

            int srcParent = findParent(parent, src);
            int destParent = findParent(parent, dest);

            if (srcParent != destParent) {
                std::cout << src << " - " << dest << "\t" << weight << "\n";
                unionSets(parent, srcParent, destParent);
                mstEdges++;
            }

            if (mstEdges == vertices - 1) {
                break;
            }
        }
    }
};

int main() {
    int numVertices, numEdges;
    std::cout << "Enter the number of vertices: ";
    std::cin >> numVertices;
    std::cout << "Enter the number of edges: ";
    std::cin >> numEdges;

    Graph graph(numVertices, numEdges);

    for (int i = 0; i < numEdges; ++i) {
        int src, dest, weight;
        std::cout << "Enter edge " << i + 1 << " source, destination, and weight: ";
        std::cin >> src >> dest >> weight;
        graph.addEdge(src, dest, weight, i);
    }

    std::cout << "Minimum Spanning Tree:\n";
    graph.kruskalMST();

    return 0;
}
