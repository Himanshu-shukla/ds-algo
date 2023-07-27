#include <iostream>
#include <vector>
#include <limits> // For std::numeric_limits

// Number of vertices in the graph
#define V 4

// Function to find the shortest paths between all pairs of vertices
void floydWarshall(std::vector<std::vector<int>>& graph) {
    int numVertices = graph.size();
    std::vector<std::vector<int>> dist(numVertices, std::vector<int>(numVertices));

    // Initialize the distance matrix with the graph values
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    // Main algorithm loop
    for (int k = 0; k < numVertices; k++) {
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {
                // If vertex k is on the shortest path from i to j,
                // then update the value of dist[i][j]
                if (dist[i][k] != std::numeric_limits<int>::max() &&
                    dist[k][j] != std::numeric_limits<int>::max() &&
                    dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print the final shortest distance matrix
    std::cout << "Shortest distances between all pairs of vertices:\n";
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            if (dist[i][j] == std::numeric_limits<int>::max()) {
                std::cout << "INF ";
            } else {
                std::cout << dist[i][j] << " ";
            }
        }
        std::cout << std::endl;
    }
}

int main() {
    // Example graph represented as an adjacency matrix
    std::vector<std::vector<int>> graph = {
        {0, 5, std::numeric_limits<int>::max(), 10},
        {std::numeric_limits<int>::max(), 0, 3, std::numeric_limits<int>::max()},
        {std::numeric_limits<int>::max(), std::numeric_limits<int>::max(), 0, 1},
        {std::numeric_limits<int>::max(), std::numeric_limits<int>::max(), std::numeric_limits<int>::max(), 0}
    };

    floydWarshall(graph);

    return 0;
}
