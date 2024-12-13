#include "pathfinder.h"

// This function returns and/or adds the index of given node
int mx_island_index(t_Graph *graph, char *island) {
    for (int i = 0; i < graph->count; ++i) {
        if (mx_strcmp(island, graph->namesArr[i]) == 0)
            return i;
    }

    graph->namesArr[graph->count] = mx_strdup(island, mx_strlen(island));
    graph->arr[graph->count] = graph->count;

    graph->count++;
    return graph->count - 1;
}
