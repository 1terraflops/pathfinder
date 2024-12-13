#include "pathfinder.h"

// This helper function that finds the unvisited node with the shortest distance
int find_shortest_distance(bool visited[], int dist[], int n) {
    int min = INT_MAX, index = -1;

    for (int i = 0; i < n; ++i) {
        if (!visited[i] && dist[i] <= min) {
            min = dist[i];
            index = i;
        }
    }
    return index;
}

// This function finds all shortest paths using Dijkstra's algorithm
void mx_dijkstra(t_Graph *graph, int src, int dest) {
    int n = graph->numNodes;
    bool visited[n];
    int dist[n];
    int **predecessors = (int **)malloc(n * sizeof(int *));

    // Initialize arrays
    for (int i = 0; i < n; ++i) {
        dist[i] = INT_MAX;
        visited[i] = false;
        predecessors[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; ++j)
            predecessors[i][j] = -1;
    }

    dist[src] = 0; 

    // Dijkstra's algorithm (this is where the whole magic happens)
    for (int count = 0; count < n - 1; ++count) {
        int u = find_shortest_distance(visited, dist, n);
        visited[u] = true;

        for (int v = 0; v < n; ++v) {
            if (!visited[v] && graph->adjMatrix[u][v] && dist[u] != INT_MAX &&
                dist[u] + graph->adjMatrix[u][v] <= dist[v]) {
                if (dist[u] + graph->adjMatrix[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph->adjMatrix[u][v];
                    mx_memset(predecessors[v], 0, n * sizeof(int));
                }
                predecessors[v][u] = 1;
            }
        }
    }

    int path[n];
    mx_print_results(graph, src, dest, path, 0, predecessors, dist);

    // Cleanup
    for (int i = 0; i < n; ++i)
        free(predecessors[i]);
    free(predecessors);
}
