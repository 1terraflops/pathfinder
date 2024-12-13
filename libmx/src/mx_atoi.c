#include "libmx.h"

long int mx_atoi(const char *str) {
    long int num = 0;
    int sign = 1;

    while (*str == ' ')
        str++;

    if (*str == '-') {
        sign = -1;
        str++;
    }
    else if (*str == '+')
        str++;

    while (*str >= '0' && *str <= '9') {
        num = num * 10 + (*str - '0');
        str++;
    }

    return num * sign;
}
