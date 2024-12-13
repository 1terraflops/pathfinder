#include "pathfinder.h"

// This function add an edge between nodes
void mx_addEdge(t_Graph *graph, int island1, int island2, int weight) {
    graph->adjMatrix[island1][island2] = weight;
    graph->adjMatrix[island2][island1] = weight;
}
