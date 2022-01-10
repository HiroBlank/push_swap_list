/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkovac <hkovac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 16:40:39 by hkovac            #+#    #+#             */
/*   Updated: 2022/01/10 13:45:01 by hkovac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

t_nb	*ft_min_t(t_nb **lst)
{
	t_nb	*tmp;
	t_nb	*save;

	save = NULL;
	tmp = *lst;
	save = tmp;
	tmp = tmp->next;
	while (tmp)
	{
		if (tmp->to_top_t < save->to_top_t)
			save = tmp;
		tmp = tmp->next;
	}
	return (save);
}

t_nb	*ft_min_value(t_nb **lst)
{
	t_nb	*tmp;
	t_nb	*save;

	save = NULL;
	tmp = *lst;
	save = tmp;
	tmp = tmp->next;
	while (tmp)
	{
		if (tmp->value < save->value)
			save = tmp;
		tmp = tmp->next;
	}
	return (save);
}

t_nb	*node_of_index(t_nb **lst, int idx)
{
	t_nb	*tmp;

	tmp = *lst;
	while (tmp->index != idx)
		tmp = tmp->next;
	return (tmp);
}

int	ft_sort(t_nb **lst)
{
	int		i;
	t_nb	*tmp;

	i = 0;
	tmp = *lst;
	while (tmp->next != NULL)
	{
		if (tmp->value > tmp->next->value)
			i++;
		tmp = tmp->next;
	}
	if (tmp->value > (*lst)->value || i > 1)
		return (0);
	if (i == 1)
	{
		while (tmp->value != (*lst)->value)
		{
			if (tmp->rot == ROT)
				rotate(lst, "ra\n");
			else
				r_rotate(lst, "rra\n");
			index_list(lst);
		}
	}
	return (1);
}
