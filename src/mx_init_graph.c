#include "pathfinder.h"

// This function creates, initializes and returns graph
t_Graph* mx_init_graph(int islands) {
    t_Graph *graph = (t_Graph *)malloc(sizeof (t_Graph));
    graph->numNodes = islands;
    graph->count = 0;

    graph->arr = (int*)malloc(islands * sizeof (int));
    for (int i = 0; i < islands; ++i) {
        graph->arr[i] = -1;
    }

    graph->namesArr = malloc(islands * sizeof(char*));
    for (int i = 0; i < islands; ++i)
        graph->namesArr[i] = NULL;

    graph->adjMatrix = (int**)malloc(islands * sizeof (int*));
    for (int i = 0; i < islands; ++i) {
        graph->adjMatrix[i] = (int*)malloc(sizeof (int) * islands);
        for (int j = 0; j < islands; ++j) {
            graph->adjMatrix[i][j] = 0;
        }
    }

    return graph;
}
