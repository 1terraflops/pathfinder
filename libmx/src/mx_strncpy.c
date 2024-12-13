#include "libmx.h"

char *mx_strncpy(char *dst, const char *src, int len) {
	if (src == NULL || dst == NULL || len < 1)
		return NULL;

	for (int i = 0; i < len; ++i)
		dst[i] = '\0';

	if (len > mx_strlen(src))
		len = mx_strlen(src);

	for (int i = 0; i < len; ++i)
		dst[i] = src[i];

	dst[len] = '\0';

	return dst;
}
