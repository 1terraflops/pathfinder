#include "pathfinder.h"

// This function check if there are 2 same islands between 1 bridge
void mx_check_duplicate(char *file) {
    char *island1 = NULL;
    char *island2 = NULL;
    char *temp = NULL;
    int fd = open(file, O_RDONLY);
    int distance;
    int line = 1;
    mx_read_line(&temp, 1, '\n', fd);
    mx_strdel(&temp);

    while (1) {
        line++;
        int test = mx_parse_islands(&distance, &island1, &island2, fd);
        if (test == 1) break;
        if (mx_strcmp(island1, island2) == 0) {
            mx_printerr("error: line ");
            char *number = mx_itoa(line);
            mx_printerr(number);
            mx_printerr(" is not valid\n");
            mx_strdel(&number);
            mx_strdel(&island1);
            mx_strdel(&island2);
            close(fd);
            exit(0);
        }
    }

    mx_strdel(&island1);
    mx_strdel(&island2);
    mx_strdel(&temp);
}
