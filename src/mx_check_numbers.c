#include "pathfinder.h"

// This function checks if weights between nodes are correct
void mx_check_numbers(char *file) {
    char *str = NULL;
    long long int sum = 0;
    int fd = open(file, O_RDONLY), line = 1;
    int index = mx_read_line(&str, 1, ',', fd);

    while (index != -1) {
        line++;
        if (str != NULL) mx_strdel(&str);
        mx_read_line(&str, 1, '\n', fd);

        if (mx_atoi(str) < 1) {
            mx_printerr("error: line ");
            char *number = mx_itoa(line);
            mx_printerr(number);
            mx_printerr(" is not valid\n");
            close(fd);
            mx_strdel(&str);
            mx_strdel(&number);
            exit(0);
        }
        sum += mx_atoi(str);
        if (str != NULL) mx_strdel(&str);
        index = mx_read_line(&str, 1, ',', fd);
        if (sum > INT_MAX) {
            mx_printerr("error: sum of bridges lengths is too big\n");
            close(fd);
            mx_strdel(&str);
            exit(0);
        }
    }

    close(fd);
    mx_strdel(&str);
}
