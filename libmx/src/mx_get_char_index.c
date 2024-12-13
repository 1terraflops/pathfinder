#include "libmx.h"

int mx_get_char_index(const char *str, char c) {
	if (str == NULL)
		return -2;

	int i = 0, len = mx_strlen(str);

	while (*str != '\0') {
		if (*str == c)
			break;
		i++;
		str++;
	}

	if (i == len)
		return -1;

	return i;
}
