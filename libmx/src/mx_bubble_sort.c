#include "libmx.h"

int mx_bubble_sort(char **arr, int size) {
	short unsigned int swaps = 0;

	for (int i = 0; i < size - 1; ++i) {
		for (int j = 0; j < size - 1 - i; ++j) {
			if (mx_strcmp(arr[j], arr[j + 1]) == 1) {
				char *temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				swaps++;
			}
		}
	}

	return swaps;
}
