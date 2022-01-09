#include "include.h"
#include <libc.h>

void print_stack(t_nb **lst)
{
	t_nb	*tmp;

	tmp = *lst;
	while (tmp)
	{
		printf("|value     :     %.5d|\n", tmp->value);
		printf("|index     :     %.5d|\n", tmp->index);
		printf("|index link:     %.5d|\n", tmp->index_link);
		printf("|to_top    :     %.5d|\n", tmp->to_top);
		printf("|to_top_t  :     %.5d|\n", tmp->to_top_t);
		printf("|rot       :     %.5d|\n", tmp->rot);
		printf("|---------------------|\n");
		tmp = tmp->next;
	}
	printf("============\n");
}