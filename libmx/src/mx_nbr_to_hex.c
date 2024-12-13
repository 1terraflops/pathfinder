#include "libmx.h"

char *mx_nbr_to_hex(unsigned long nbr) {
	if (nbr == 0) {
		char *zero = "0\0";
		return zero;
	}

	unsigned long remainder;
	char temp_result[17];

	int counter = 0;
	while (nbr > 0) {
		remainder = nbr % 16;
		nbr /= 16;
		if (remainder < 10)
			temp_result[counter++] = remainder + '0';
		else
			temp_result[counter++] = 'a' + (remainder - 10);
	}

	temp_result[counter] = '\0';
	char *result = malloc(counter + 1);
    if (result != NULL) {
        for (int i = 0; i < counter; i++) {
            result[i] = temp_result[counter - i - 1];
        }
        result[counter] = '\0';
    }

	return result;
}
