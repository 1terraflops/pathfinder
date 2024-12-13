#include "libmx.h"

void mx_push_back(t_list **list, void *data) {
	t_list *tail = (t_list *)malloc(sizeof(t_list));
	tail->data = data;
	tail->next = NULL;

	if (*list == NULL)
		*list = tail;
	else {
		t_list *temp = *list;
		while (temp->next != NULL)
			temp = temp->next;

		temp->next = tail;
	}
	
}
