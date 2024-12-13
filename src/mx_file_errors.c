#include "pathfinder.h"

// This function checks if everything is okay with the given file
void mx_file_errors(int argc, char *file) {
    if (argc != 2) {
        mx_printerr("usage: ./pathfinder [filename]\n");
        exit(0);
    }

    int fd = open(file, O_RDONLY);
    if (fd == -1) {
        mx_printerr("error: file ");
        mx_printerr(file);
        mx_printerr(" does not exist\n");
        close(fd);
        exit(0);
    }

    char temp;
    int check_read = read(fd, &temp, 1);
    close(fd);

    if (check_read == 0) {
        mx_printerr("error: file ");
        mx_printerr(file);
        mx_printerr(" is empty\n");
        exit(0);
    }
}
