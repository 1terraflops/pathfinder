#include "libmx.h"

void *mx_memmove(void *dst, const void *src, size_t len) {
	unsigned char *dstPtr = (unsigned char *)dst;
	unsigned char *srcPtr = (unsigned char *)src;
	unsigned char *temp = malloc(len);

	for (size_t i = 0; i < len; ++i)
		temp[i] = srcPtr[i];

	for (size_t i = 0; i < len; ++i)
		dstPtr[i] = temp[i];

	free(temp);

	return dst;
}
