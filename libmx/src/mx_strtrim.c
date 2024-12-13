#include "libmx.h"

char *mx_strtrim(const char *str) {
    if (str == NULL)
        return NULL;

    const char *start = str;
    const char *end = str + mx_strlen(str) - 1;

    while (*start != '\0' && (*start < 33 || *start > 126))
        start++;
    while (end > start && (*end < 33 || *end > 126))
        end--;

    int length = end - start + 1;
    char *trimmed_string = mx_strndup(start, length);

    return trimmed_string;
}
