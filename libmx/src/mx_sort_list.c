#include "libmx.h"

t_list *mx_sort_list(t_list *lst, bool (*cmp)(void *, void *)) {
	if (lst == NULL || lst->next == NULL) return lst;
	bool swapped = true;
    t_list *node, *last = NULL;
    while (swapped) {
        swapped = false;
        node = lst;
        while (node->next != last) {
            if (cmp(node->data, node->next->data)) {
                void *temp = node->data;
                node->data = node->next->data;
                node->next->data = temp;
                swapped = true;
            }
            node = node->next;
        }
        last = node;
    }
    return lst;
}
