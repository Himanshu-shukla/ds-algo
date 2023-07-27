#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Structure to represent an edge
struct Edge {
    int source;
    int destination;
    int weight;
};

// Structure to represent a graph
struct Graph {
    int V;              // Number of vertices in the graph
    int E;              // Number of edges in the graph
    vector<Edge> edges; // Vector of edges
};

// Function to create a graph
Graph createGraph(int V, int E) {
    Graph graph;
    graph.V = V;
    graph.E = E;
    graph.edges.resize(E);
    return graph;
}

// Function to perform the Bellman-Ford algorithm
void bellmanFord(Graph& graph, int source) {
    int V = graph.V;
    int E = graph.E;
    vector<int> dist(V, INT_MAX);

    // Initialize the distance array with infinity
    dist[source] = 0;

    // Relax all edges V - 1 times
    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = graph.edges[j].source;
            int v = graph.edges[j].destination;
            int weight = graph.edges[j].weight;

            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }

    // Check for negative-weight cycles
    for (int i = 0; i < E; i++) {
        int u = graph.edges[i].source;
        int v = graph.edges[i].destination;
        int weight = graph.edges[i].weight;

        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            cout << "Graph contains a negative-weight cycle." << endl;
            return;
        }
    }

    // Print the shortest distances from the source
    cout << "Shortest distances from vertex " << source << ":" << endl;
    for (int i = 0; i < V; i++) {
        if (dist[i] == INT_MAX)
            cout << "Vertex " << i << ": Not reachable" << endl;
        else
            cout << "Vertex " << i << ": " << dist[i] << endl;
    }
}

int main() {
    int V, E, source;

    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;

    Graph graph = createGraph(V, E);

    cout << "Enter the source vertex: ";
    cin >> source;

    cout << "Enter the edges (source destination weight):" << endl;
    for (int i = 0; i < E; i++) {
        cin >> graph.edges[i].source >> graph.edges[i].destination >> graph.edges[i].weight;
    }

    bellmanFord(graph, source);

    return 0;
}
