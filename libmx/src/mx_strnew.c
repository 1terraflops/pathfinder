#include "libmx.h"

char *mx_strnew(const int size) {
	if (size < 1)
		return NULL;

	char *result = malloc(size + 1);

	if (result == NULL)
		return NULL;

	for (int i = 0; i < size + 1; ++i)
		result[i] = '\0';

	return result;
}
