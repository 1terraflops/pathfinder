#include "libmx.h"

void mx_pop_front(t_list **head) {
	t_list *temp = (*head)->next;
	free(*head);
	*head = temp;
}
