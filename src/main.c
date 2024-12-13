#include "pathfinder.h"

int main(int argc, char *argv[]) {
    // Check for errors
    mx_check_for_errors(argc, argv[1]);

    // Declaration of some variables
    int distance, fd = open(argv[1], O_RDONLY), islands = mx_get_num_of_islands(fd);
    char *island1 = NULL, *island2 = NULL;

    // Graph initialization
    t_Graph *graph = mx_init_graph(islands);

    // PARSE the file -> ADD edges
    while (1) {
        int test = mx_parse_islands(&distance, &island1, &island2, fd);
        if (test == 1) break;
        mx_addEdge(graph, mx_island_index(graph, island1), mx_island_index(graph, island2), distance);
    }

    // CALCULATE the shortest path -> OUTPUT the results
    for (int i = 0; i < islands; ++i) {
        for (int j = i + 1; j < islands; ++j)
            mx_dijkstra(graph, i, j);
    }

    // Cleanup
    close(fd);
    mx_strdel(&island1);
    mx_strdel(&island2);
    free(graph->arr);
    for (int i = 0; i < islands; ++i) {
        if (graph->namesArr[i] != NULL) {
            free(graph->namesArr[i]);
        }
    }
    free(graph->namesArr);
    for (int i = 0; i < islands; ++i)
        free(graph->adjMatrix[i]);
    free(graph->adjMatrix);
    free(graph);
    return 0;
}
