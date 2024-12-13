#include "libmx.h"

char *mx_strcat(char *restrict s1, const char *restrict s2) {
	if (s1 == NULL || s2 == NULL)
		return NULL;

	int len = mx_strlen(s1);
	int i = 0;
	while (s2[i] != '\0') {
		s1[len + i] = s2[i];
		i++;
	}

	s1[len + i] = '\0';

	return s1;
}
