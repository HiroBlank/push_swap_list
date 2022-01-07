#include "include.h"
#include <libc.h>

void print_stack(t_nb **lst)
{
	t_nb	*tmp;

	tmp = *lst;
	while (tmp)
	{
		printf("%d\n", tmp->value);
		tmp = tmp->next;
	}
}