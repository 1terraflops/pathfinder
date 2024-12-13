#include "libmx.h"

char *mx_strdup(const char *s1, size_t n) {
	if (s1 == NULL || n < 1)
		return NULL;

	char *dup = mx_strnew(n);

	if (dup == NULL)
        return NULL;

	int i = 0;
	while (s1[i] != '\0') {
		dup[i] = s1[i];
		i++;
	}

	return dup;
}
