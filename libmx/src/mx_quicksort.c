#include "libmx.h"

void swap_strings(char **a, char **b) {
    char *temp = *a;
    *a = *b;
    *b = temp;
}

int partition(char **arr, int left, int right) {
	int pivot = mx_strlen(arr[right]);
	int i = left - 1;

	for (int j = left; j < right; ++j) {
		if (mx_strlen(arr[j]) < pivot) {
			i++;
			swap_strings(&arr[i], &arr[j]);
		}
	}

	swap_strings(&arr[i + 1], &arr[right]);
	return i + 1;
}

int mx_quicksort(char **arr, int left, int right) {
	if (arr == NULL)
		return -1;

	int iterations = 0;

	if (left < right) {
		int pivot = partition(arr, left, right);
		iterations += mx_quicksort(arr, left, pivot - 1);
		iterations += mx_quicksort(arr, pivot + 1, right);
		iterations++;
	}

	return iterations;
}
