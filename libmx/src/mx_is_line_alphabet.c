#include "libmx.h"

bool mx_is_line_alphabet(char *str) {
    if (str == NULL)
        return false;

    while (*str != '\0') {
        if ((*str < 'a' || *str > 'z') && (*str < 'A' || *str > 'Z')) {
            return false;
        }
        str++;
    }

    return true;
}
