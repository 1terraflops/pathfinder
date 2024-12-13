#include "pathfinder.h"

// This function prints all the resulting paths
void mx_print_results(t_Graph *graph, int src, int dest, int *path, int path_index, int **predecessors, int *dist) {
    path[path_index] = dest;

    if (dest == src) {
        mx_printstr("========================================\n");
        mx_printstr("Path: ");
        mx_printstr(graph->namesArr[src]);
        mx_printstr(" -> ");
        mx_printstr(graph->namesArr[path[0]]);

        mx_printstr("\nRoute: ");
        for (int i = path_index; i >= 0; --i) {
            mx_printstr(graph->namesArr[path[i]]);
            if (i > 0) mx_printstr(" -> ");
        }

        mx_printstr("\nDistance: ");
        int total_distance = 0;
        for (int i = path_index; i > 0; --i) {
            int weight = graph->adjMatrix[path[i]][path[i - 1]];
            total_distance += weight;
            mx_printint(weight);
            if (i > 1) mx_printstr(" + ");
        }
        if (path_index > 1) {
            mx_printstr(" = ");
            mx_printint(total_distance);
        }
        mx_printchar('\n');
        mx_printstr("========================================\n");
        return;
    }

    for (int i = 0; i < graph->numNodes; ++i) {
        if (predecessors[dest][i])
            mx_print_results(graph, src, i, path, path_index + 1, predecessors, dist);
    }
}
