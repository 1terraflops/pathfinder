#include "libmx.h"

char *mx_strndup(const char *s1, size_t n) {
	if (s1 == NULL || n < 1)
		return NULL;
	int size = n;

	if (size > mx_strlen(s1))
		size = mx_strlen(s1);

	char *ndup = mx_strnew(n);
	if (ndup == NULL)
		return NULL;

	int i = 0;
	while (i < size) {
		ndup[i] = s1[i];
		i++;
	}

	return ndup;
}
