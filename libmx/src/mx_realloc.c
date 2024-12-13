#include "libmx.h"

void *mx_realloc(void *ptr, size_t size) {
	if (ptr == NULL)
        return malloc(size);

    if (size < 1) {
        free(ptr);
        return NULL;
    }

	size_t current_size = malloc_size(ptr);
	void *newPtr = malloc(size);
	if (newPtr == NULL)
		return NULL;

	mx_memmove(newPtr, ptr, current_size);
	free(ptr);
			
	return newPtr;
}
