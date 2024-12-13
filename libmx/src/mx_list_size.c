#include "libmx.h"

int mx_list_size(t_list *list) {
	if (list == NULL)
		return 0;

	int counter = 0;
	t_list *temp = list;
	while (temp != NULL) {
		counter++;
		temp = temp->next;
	}

	return counter;
}
