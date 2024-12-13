#include "libmx.h"

char *mx_strjoin(const char *s1, const char *s2) {
	if (s1 == NULL && s2 == NULL) return NULL;
	int i, j;
	if (s1 == NULL) {
		char *str = mx_strnew(mx_strlen(s2));
		for (i = 0; s2[i] != '\0'; ++i)
			str[i] = s2[i];
		return str;
	}
	if (s2 == NULL) {
		char *str = mx_strnew(mx_strlen(s1));
			for (i = 0; s1[i] != '\0'; ++i)
				str[i] = s1[i];
		return str;
	}
	char *str = mx_strnew(mx_strlen(s1) + mx_strlen(s2));
	for (i = 0; s1[i] != '\0'; ++i)
		str[i] = s1[i];
	for (j = 0; s2[j] != '\0'; ++j)
		str[i++] = s2[j];
	return str;
}
