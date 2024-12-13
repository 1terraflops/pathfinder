#include "libmx.h"

char *mx_del_extra_spaces(const char *str) {
	if (str == NULL)
		return NULL;
	int i = 0, j = 0;
	char *dup = mx_strnew(mx_strlen(str));

	while (*str < '!')
		str++;
	while(str[i] != '\0') {
		if (str[i] > '!')
			dup[j++] = str[i];
		else if (str[i] == ' ' && str[i + 1] > '!' && str[i + 1] != '\0')
			dup[j++] = str[i];
		i++;
	}
	char *result = mx_strnew(j);
	mx_strcpy(result, dup);
	mx_strdel(&dup);
	return result;
}
