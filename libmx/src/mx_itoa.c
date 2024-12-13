#include "libmx.h"

int numLength(int num) {
	int len = 0;

	if (num < 0)
		num *= -1;

	while (num > 0) {
		num /= 10;
		len++;
	}
	return len;
}

char *mx_itoa(int number) {
	int length = numLength(number);
	bool isNegative = 0;

	if (number == 0) {
		char *zero = malloc(2);
		zero[0] = '0';
		zero[1] = '\0';
		return zero;
	}

	if (number < 0) {
		number *= -1;
		isNegative = 1;
	}

	char arr[length];
	for (int i = 0; i < length; ++i) {
		arr[i] = number % 10;
		number /= 10;
	}

	char *result = NULL;
	result = malloc(length + isNegative + 1);
	if (isNegative)
			result[0] = '-';

	for (int i = 0 + isNegative; i < length + isNegative; ++i)
		result[i] = arr[length - i - 1 + isNegative] + '0';

	result[length + isNegative] = '\0';
	return result;
}
