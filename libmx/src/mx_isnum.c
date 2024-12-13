#include "libmx.h"

bool mx_isnum(char *num) {
    if (num == NULL || *num == '\0')
        return false;

    while (*num != '\0') {
        if (*num < 48 || *num > 57)
            return false;

        num++;
    }

    return true;
}
