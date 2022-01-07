#include "include.h"
#include <libc.h>

void print_stack(t_nb **lst)
{
	t_nb	*tmp;

	tmp = *lst;
	while (tmp)
	{
		printf("value : 	 %d\n", tmp->value);
		printf("index :		 %d\n", tmp->index);
		printf("index link:	 %d\n", tmp->index_link);
		printf("---------------\n");
		tmp = tmp->next;
	}
	printf("============\n");
}