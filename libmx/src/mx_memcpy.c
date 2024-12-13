#include "libmx.h"

void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n) {
	if (dst == NULL || src == NULL || n == 0)
		return NULL;

	char *destPtr1 = (char *)dst;
	char *srcPtr2 = (char *)src;
	for (size_t i = 0; i < n; ++i)
		destPtr1[i] = srcPtr2[i];

	return dst;
}
