#include "pathfinder.h"

// This is a mini function that extracts the number of islands from the file
int mx_get_num_of_islands(const int fd) {
    char *temp = NULL;
    mx_read_line(&temp, 1, '\n', fd);

    int number = mx_atoi(temp);

    mx_strdel(&temp);
    return number;
}
