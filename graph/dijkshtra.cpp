#include <iostream>
#include <vector>
#include <queue>
#include <limits>

const int INF = std::numeric_limits<int>::max();

// Graph class to represent a weighted graph using an adjacency list
class Graph {
private:
    int numVertices;
    std::vector<std::vector<std::pair<int, int>>> adjList;

public:
    Graph(int vertices) : numVertices(vertices), adjList(vertices) {}

    // Function to add an edge with a weight between two vertices
    void addEdge(int src, int dest, int weight) {
        adjList[src].push_back(std::make_pair(dest, weight));
        adjList[dest].push_back(std::make_pair(src, weight)); // For undirected graph
    }

    // Dijkstra's Algorithm implementation
    std::vector<int> dijkstra(int startVertex) {
        std::vector<int> distance(numVertices, INF);
        distance[startVertex] = 0;

        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
        pq.push(std::make_pair(0, startVertex));

        while (!pq.empty()) {
            int currentVertex = pq.top().second;
            int currentDist = pq.top().first;
            pq.pop();

            if (currentDist > distance[currentVertex]) {
                continue;
            }

            for (const auto& neighbor : adjList[currentVertex]) {
                int nextVertex = neighbor.first;
                int weight = neighbor.second;

                if (currentDist + weight < distance[nextVertex]) {
                    distance[nextVertex] = currentDist + weight;
                    pq.push(std::make_pair(distance[nextVertex], nextVertex));
                }
            }
        }

        return distance;
    }
};

int main() {
    int numVertices = 6;
    Graph graph(numVertices);

    graph.addEdge(0, 1, 4);
    graph.addEdge(0, 2, 1);
    graph.addEdge(1, 2, 2);
    graph.addEdge(1, 3, 5);
    graph.addEdge(2, 3, 8);
    graph.addEdge(2, 4, 10);
    graph.addEdge(3, 4, 2);
    graph.addEdge(3, 5, 6);
    graph.addEdge(4, 5, 7);

    int startVertex = 0;
    std::vector<int> shortestDistances = graph.dijkstra(startVertex);

    std::cout << "Shortest distances from vertex " << startVertex << ":\n";
    for (int i = 0; i < numVertices; ++i) {
        std::cout << "Vertex " << i << ": " << shortestDistances[i] << std::endl;
    }

    return 0;
}
