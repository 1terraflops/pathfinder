#include "libmx.h"

void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len) {
	unsigned char *ptrMain = (unsigned char *)big;
	unsigned char *ptrSub = (unsigned char *)little;

	if (big_len < little_len)
		return NULL;

	if (little_len == 0)
		return ptrMain;

	for (size_t i = 0; i < big_len - little_len; ++i) {
		if (*ptrMain == *ptrSub) {
			if (mx_memcmp(ptrMain, ptrSub, little_len) == 0)
				return ptrMain;
		}

		ptrMain++;
	}
	return NULL;
}
