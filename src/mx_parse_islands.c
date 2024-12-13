#include "pathfinder.h"

// This is the parser function that extracts useful information from the given file
int mx_parse_islands(int *distance, char **island1, char **island2, const int fd) {
    char *str = NULL;
    int test;

    if (*island1 != NULL) mx_strdel(island1);
    if (*island2 != NULL) mx_strdel(island2);

    test = mx_read_line(island1, 1, '-', fd);
    if (test <= 0) return 1;
    mx_read_line(island2, 1, ',', fd);
    mx_read_line(&str, 1, '\n', fd);
    if (!mx_isnum(str)) {
        mx_strdel(&str);
        return 2;
    }
    *distance = mx_atoi(str);

    mx_strdel(&str);
    return 0;
}
