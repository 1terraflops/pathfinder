#include "libmx.h"

char *mx_replace_substr(const char *str, const char *sub, const char *replace) {
	if (str == NULL || sub == NULL || replace == NULL) return NULL;
	int subSize = mx_strlen(sub), repSize = mx_strlen(replace), count = 0, i = 0, j = 0;
	for (int i = 0; str[i] != '\0'; i++) {
		if (mx_strncmp(&str[i], sub, subSize) == 0) {
			count++;
			i += subSize - 1;
		}
	}
	char *result = mx_strnew(mx_strlen(str) + (repSize - subSize) * count);
	while (str[i] != '\0') {
		if (mx_strncmp(&str[i], sub, subSize) == 0) {
			for (int k = 0; k < repSize; k++)
				result[j++] = replace[k];
			i += subSize;
		} else {
			result[j++] = str[i++];
		}
	}
	result[j] = '\0';
	return result;
}
