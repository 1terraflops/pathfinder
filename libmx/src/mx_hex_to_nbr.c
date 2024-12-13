#include "libmx.h"

unsigned long mx_hex_to_nbr(const char *hex) {
	if (hex == NULL || *hex == '\0')
        return 0;

	unsigned long result = 0;
	for (int i = 0; hex[i] != '\0'; ++i) {
		if(hex[i] >= '0' && hex[i] <= '9')
			result = result * 16 + (hex[i] - '0');

		else if(hex[i] >= 'a' && hex[i] <= 'f')
			result = result * 16 + (hex[i] - 'a' + 10);

		else if(hex[i] >= 'A' && hex[i] <= 'F')
			result = result * 16 + (hex[i] - 'A' + 10);

		else
			return 0;
	}
	return result;
}
