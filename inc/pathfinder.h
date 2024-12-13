#ifndef PATHFINDER_H
#define PATHFINDER_H

#define INT_MAX 2147483647
#define INT_MIN -2147483647

#include "libmx.h"

void mx_file_errors(int argc, char *file);
void mx_check_numbers(char *file);
void mx_check_number_of_islands(char *file);
void mx_check_line_format(char *file);
void mx_check_duplicate(char *file);
void mx_check_if_nums_match(char *file);
void mx_check_for_duplicate_bridges(char *file);
void mx_check_for_errors(int argc, char *file);
int mx_parse_islands(int *distance, char **island1, char **island2, const int fd);
int mx_get_num_of_islands(const int fd);

typedef struct s_Graph {
    int numNodes;
    int **adjMatrix;
    int count;
    int *arr;
    char **namesArr;
} t_Graph;

t_Graph* mx_init_graph(int islands);
void mx_print_results(t_Graph *graph, int src, int dest, int *path, int path_index, int **predecessors, int *dist);
void mx_addEdge(t_Graph *graph, int island1, int island2, int weight);
int mx_island_index(t_Graph *graph, char *island);
void mx_dijkstra(t_Graph *graph, int src, int dest);

#endif
