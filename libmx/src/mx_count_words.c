#include "libmx.h"

int mx_count_words(const char *str, char c) {
	if (str == NULL)
		return -1;

	int words = 1, start = 0;
	while (str[start] == c)
		start++;

	while (str[start + 1] != '\0') {
		if (str[start] == c && str[start + 1] != c) {
			words++;
			while (str[start] == c)
			start++;
		}
		else
			start++;
	}
	return words;
}
