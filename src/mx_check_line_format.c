#include "pathfinder.h"

// This function checks if the lines format matches with the story
void mx_check_line_format(char *file) {
    char *island1 = NULL;
    char *island2 = NULL;
    int distance = 0, line = 1;
    int fd = open(file, O_RDONLY);

    mx_read_line(&island1, 1, '\n', fd);
    mx_strdel(&island1);

    while (1) {
        line++;
        int test = mx_parse_islands(&distance, &island1, &island2, fd);
        if (test == 1) break;
        if (!mx_is_line_alphabet(island1) || !mx_is_line_alphabet(island2)
            || test == 2) {
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
    close(fd);
}
