#include "libmx.h"

void mx_printstr(const char *s) {
	while (*s != '\0') {
		mx_printchar(*s);
		s++;
	}
}
