/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_10.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkovac <hkovac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 12:39:49 by hkovac            #+#    #+#             */
/*   Updated: 2022/01/10 18:25:05 by hkovac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int	ft_sort_simple(t_nb **lst, int size)
{
	int		i;
	t_nb	*tmp;

	if (lst_size(lst) != size)
		return (0);
	i = 0;
	tmp = *lst;
	while (tmp->next != NULL)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	algo_10(t_nb **lst_a, t_nb **lst_b)
{
	t_nb	*tmp;

	while (lst_size(lst_a) != 1)
	{
		tmp = ft_min_value(lst_a);
		if (tmp->value == (*lst_a)->value)
			push(lst_a, lst_b, "pb\n");
		else if ((*lst_a)->value > (*lst_a)->next->value)
			swap(lst_a, "sa\n");
		else
			r_rotate(lst_a, "rra\n");
	}
	while (lst_size(lst_b) != 0)
		push(lst_b, lst_a, "pa\n");
}
