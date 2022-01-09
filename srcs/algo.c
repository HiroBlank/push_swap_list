/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkovac <hkovac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 15:48:22 by hkovac            #+#    #+#             */
/*   Updated: 2022/01/09 21:27:23 by hkovac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

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

void	push_all(t_nb **lst_a, t_nb **lst_b)
{
	t_nb	*tmp_a;
	int		max;

	tmp_a = *lst_a;
	max = ft_max(lst_a);
	while (lst_size(lst_a) > 1)
	{
		tmp_a = *lst_a;
		if (tmp_a->value == max)
			rotate(lst_a, "ra\n");
		else
			push(lst_a, lst_b, "pb\n");
	}
}

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

void	algo(t_nb **lst_a, t_nb **lst_b)
{
	t_nb	*min;

	push_all(lst_a, lst_b);
	all_specs(lst_a, lst_b);
	while (lst_size(lst_b))
	{
		all_specs(lst_a, lst_b);
		to_top_a(lst_a, to_top_b(lst_b));
		push(lst_b, lst_a, "pa\n");
	}
	min = ft_min_value(lst_a);
	while ((*lst_a)->value != min->value)
	{
		if (min->rot == ROT)
			rotate(lst_a, "ra\n");
		else
			r_rotate(lst_a, "rra\n");
		index_list(lst_a);
	}
}
