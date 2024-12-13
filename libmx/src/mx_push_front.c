#include "libmx.h"

void mx_push_front(t_list **list, void *data) {
	t_list *head = (t_list *)malloc(sizeof(t_list));
	head->data = data;
	head->next = *list;
	*list = head;
}
