#include "libmx.h"

void *mx_memccpy(void *restrict dst, const void *restrict src, int c, size_t n) {
	char *dstPtr = (char *)dst;
	char *srcPtr = (char *)src;
	for (size_t i = 0; i < n; ++i) {
		dstPtr[i] = srcPtr[i];
		if (srcPtr[i] == (char)c)
			return dst;
	}

	return NULL;
}
