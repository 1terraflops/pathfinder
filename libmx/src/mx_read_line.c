#include "libmx.h"

int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd) {
    if (buf_size == 0 || buf_size >= 2147483648)
        return -2;
    if (fd < 0)
        return -2;

    char *buf = mx_strnew(buf_size);
    char *str = mx_strnew(buf_size);
    size_t read_bytes;
    int delim_index = -1;

    while ((read_bytes = read(fd, buf, buf_size)) > 0) {
        char *new_str = mx_strjoin(str, buf);
        free(str);
        str = new_str;

        delim_index = mx_get_char_index(str, delim);
        if (delim_index != -1)
            break;
    }

    if (read_bytes < 0) {
        free(buf);
        free(str);
        return -1;
    }

    if (delim_index == -1 && str[0] == '\0') {
        free(buf);
        free(str);
        return -1;
    }

    if (delim_index == -1) {
        *lineptr = str;
        free(buf);
        return -1;
    }

    *lineptr = mx_strndup(str, delim_index);
    free(buf);
    free(str);
    return 1;
}
