#include "pathfinder.h"

// This function checks if the format of the first line is correct
void mx_check_number_of_islands(char *file) {
    char *line = NULL;
    int fd = open(file, O_RDONLY);

    if (mx_read_line(&line, 1, '\n', fd) <= 0 || !mx_isnum(line) ||
        mx_atoi(line) < 1 || line[0] == '0' || mx_atoi(line) > INT_MAX) {
        close(fd);
        mx_printerr("error: line 1 is not valid\n");
        mx_strdel(&line);
        exit(0);
    }

    mx_strdel(&line);
    close(fd);
}
