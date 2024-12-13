#include "libmx.h"

void *mx_memrchr(const void *s, int c, size_t n) {
	unsigned char* ptr = (unsigned char*)s;
	size_t size = mx_strlen(s);
	if (n > size)
		n = size;

	for (size_t i = 0; i < n; ++i)
		ptr++;

	for (size_t i = 0; i < n; ++i) {
		if (*ptr == (char)c)
			return ptr;

		ptr--;
	}

	return NULL;
}
