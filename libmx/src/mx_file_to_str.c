#include "libmx.h"

char *mx_file_to_str(const char *file) {
	if (file == NULL) return NULL;
	int fd, size = 0;;
	char *buffer = NULL;
	fd = open(file, O_RDONLY);
	if (fd == -1) return NULL;
	while (read(fd, &buffer, 1))
		size++;
	close(fd);
	if (buffer == NULL) return NULL;
	buffer = mx_strnew(size);
	fd = open(file, O_RDONLY);
	if (fd == -1) return NULL;
	ssize_t characters_read = read(fd, buffer, size);
	if (characters_read == -1) return NULL;
	close(fd);

	buffer[size] = '\0';
	return buffer;
}
