/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkovac <hkovac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 13:14:20 by hkovac            #+#    #+#             */
/*   Updated: 2022/01/07 14:50:12 by hkovac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	index_list(t_nb **lst)
{
	t_nb	*tmp;
	int		i;

	i = 0;
	tmp = *lst;
	while (tmp)
	{
		tmp->index = lst_size(lst) - i - 1;
		tmp = tmp ->next;
		i++;
	}
}

#include <libc.h>
t_nb	*index_link_init(t_nb **lst_a, int value)
{
	t_nb	*tmp_a;
	t_nb	*save;

	save = NULL;
	tmp_a = *lst_a;
	
	while (tmp_a && !save)
	{
		if (tmp_a->value > value)
			save = tmp_a;
		tmp_a = tmp_a->next;
	}
	if (!save)
		return (NULL);
	return (save);	
}

void	index_link_list(t_nb **lst_a, t_nb **lst_b)
{
	t_nb	*tmp_a;
	t_nb	*tmp_b;
	t_nb	*save;

	tmp_b = *lst_b;
	save = NULL;
	while (tmp_b)
	{
		save = index_link_init(lst_a, tmp_b->value);
		if (save)
		{
		tmp_a = *lst_a;
			while (tmp_a)
			{
				if (tmp_a->value > tmp_b->value)
					if (tmp_a->value < save->value)
						save = tmp_a;
				tmp_a = tmp_a->next;
			}
			tmp_b->index_link = save->index;
		}
		tmp_b = tmp_b->next;
	}
}