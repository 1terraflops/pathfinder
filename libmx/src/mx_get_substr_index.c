#include "libmx.h"

int mx_get_substr_index(const char *str, const char *sub) {
	if (str == NULL || sub == NULL)
		return -2;

	int sub_len = mx_strlen(sub);
	for (int i = 0; str[i] != '\0'; ++i) {
		if (str[i] == sub[0]) {
			for (int j = 0; j < sub_len && str[i + j] != '\0'; ++j) {
				if (str[i + j] != sub[j]) {
					break;
				}
				if (j == sub_len - 1)
					return i;
			}
		}
	}

	return -1;
}
