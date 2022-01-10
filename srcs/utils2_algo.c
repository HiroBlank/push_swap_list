/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkovac <hkovac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 17:34:15 by hkovac            #+#    #+#             */
/*   Updated: 2022/01/10 18:24:54 by hkovac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int	to_top_b(t_nb **lst)
{
	t_nb	*tmp;

	tmp = ft_min_t(lst);
	index_list(lst);
	while ((*lst)->index != tmp->index)
	{
		if (tmp->rot == ROT)
			rotate(lst, "rb\n");
		else
			r_rotate(lst, "rrb\n");
		index_list(lst);
	}
	return (tmp->index_link);
}

void	to_top_a(t_nb **lst, int idx)
{
	t_nb	*tmp;

	tmp = *lst;
	while (tmp->index != idx)
		tmp = tmp->next;
	while ((*lst)->index != tmp->index)
	{
		if (tmp->rot == ROT)
			rotate(lst, "ra\n");
		else
			r_rotate(lst, "rra\n");
		index_list(lst);
	}
}

int	ft_max(t_nb **lst)
{
	t_nb	*tmp;
	int		max;

	tmp = *lst;
	max = tmp->value;
	tmp = tmp->next;
	while (tmp)
	{
		if (tmp->value > max)
			max = tmp->value;
		tmp = tmp->next;
	}
	return (max);
}
