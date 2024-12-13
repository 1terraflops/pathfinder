#include "libmx.h"

char *mx_strstr(const char *haystack, const char *needle) {
	if (haystack == NULL)
		return NULL;
	if (needle == NULL)
		return (char *)haystack;
	int needle_len = mx_strlen(needle);
	for (int i = 0; haystack[i] != '\0'; ++i) {
		if (haystack[i] == needle[0]) {
			int j = 0;
			while (j < i + needle_len && haystack[i + j] != '\0') {
				if (haystack[i + j] != needle[j])
					break;
				j++;
			}
			if (j == needle_len)
				return (char *)&haystack[i];
		}
	}
	return NULL;
}
