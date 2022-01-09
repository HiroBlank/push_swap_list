/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkovac <hkovac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 13:14:20 by hkovac            #+#    #+#             */
/*   Updated: 2022/01/09 21:47:08 by hkovac           ###   ########.fr       */
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

void	move_list(t_nb **lst)
{
	t_nb	*tmp;
	int		size;

	tmp = *lst;
	size = lst_size(lst);
	while (tmp)
	{
		if (tmp->index >= size / 2)
		{
			tmp->to_top = size - tmp->index - 1;
			tmp->rot = ROT;
		}
		else
		{
			tmp->to_top = tmp->index + 1;
			tmp->rot = RROT;
		}
		tmp = tmp->next;
	}
}

void	move_list_t(t_nb **lst_a, t_nb **lst_b)
{
	t_nb	*tmp_a;
	t_nb	*tmp_b;
	int		size_a;

	tmp_a = *lst_a;
	tmp_b = *lst_b;
	size_a = lst_size(lst_a);
	while (tmp_a && tmp_b)
	{
		tmp_a = *lst_a;
		while (tmp_b->index_link != tmp_a->index)
			tmp_a = tmp_a->next;
		tmp_b->to_top_t = tmp_b->to_top + tmp_a->to_top + 1;
		tmp_b = tmp_b->next;
	}
}
