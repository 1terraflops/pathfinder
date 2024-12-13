#include "libmx.h"

int _length(const char *s, char c) {
	int i = 0;

	while (*s != '\0') {
		if (*s != c) {
			i++;
		}
		s++;
	}

	return i;
}

char **mx_strsplit(const char *s, char c) {
	if (s == NULL) return NULL;
	int count = _length(s, c), length = 0, i = 0;
	const char *start = s;
	char **arr = (char **)malloc((count + 1) * sizeof(char *));
	s = start;
	while (*s != '\0') {
		if (*s != c) {
			const char *word_begin = s;
			while (*s != '\0' && *s != c) {
				s++;
				length++;
			}
			arr[i++] = mx_strndup(word_begin, length);
			length = 0;
		} else
			s++;
	}
	arr[i] = NULL;
	return arr;
}
