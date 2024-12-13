#include "libmx.h"

void mx_str_reverse(char *s) {
	if (s != NULL && *s != '\0') {
		int len = mx_strlen(s) - 1;
		int i = 0;
		while (len > i) {
			mx_swap_char(&s[i], &s[len]);
			i++;
			len--;
		}
	}
}
