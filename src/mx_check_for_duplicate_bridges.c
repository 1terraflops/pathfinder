#include "pathfinder.h"

// Helper function that return an index of node
int island_index(char **islandsArr, char *island, int *count) {
    for (int i = 0; i < *count; ++i) {
        if (mx_strcmp(islandsArr[i], island) == 0)
            return i;
    }

    islandsArr[*count] = mx_strdup(island, mx_strlen(island));
    (*count)++;
    return *count - 1;
}

// Helper function that adds a new edge between islands
int add_new_edge(int **matrix, int src, int dst, int weight) {
    if (matrix[src][dst] != -1)
        return 2;

    matrix[src][dst] = weight;
    matrix[dst][src] = weight;

    return 0;
}

// This function checks if there are 2 identical edges between nodes
void mx_check_for_duplicate_bridges(char *file) {
    char *island1 = NULL;
    char *island2 = NULL;
    int fd = open(file, O_RDONLY), num_of_islands = mx_get_num_of_islands(fd);
    int distance, test, count = 0;
    int **matrix = (int**)malloc(num_of_islands * sizeof (int*));
    for (int i = 0; i < num_of_islands; ++i) {
        matrix[i] = (int*)malloc(num_of_islands * sizeof (int));
        for (int j = 0; j < num_of_islands; ++j) {
            matrix[i][j] = -1;
        }
    }
    char **islandsArr = malloc(num_of_islands * sizeof(char*));
    for (int i = 0; i < num_of_islands; ++i)
        islandsArr[i] = NULL;

    while (1) {
        test = mx_parse_islands(&distance, &island1, &island2, fd);
        if (test == 1) break;

        int index1 = island_index(islandsArr, island1, &count);
        int index2 = island_index(islandsArr, island2, &count);

        test = add_new_edge(matrix, index1, index2, distance);
        if (test == 2) break;
    }

    for (int i = 0; i < num_of_islands; ++i)
        free(islandsArr[i]);
    free(islandsArr);
    for (int i = 0; i < num_of_islands; ++i) {
        free(matrix[i]);
    }
    free(matrix);
    mx_strdel(&island1);
    mx_strdel(&island2);
    close(fd);

    if (test == 2) {
        mx_printerr("error: duplicate bridges\n");
        exit(1);
    }
}
