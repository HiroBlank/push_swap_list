/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkovac <hkovac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 15:48:22 by hkovac            #+#    #+#             */
/*   Updated: 2022/01/10 18:24:01 by hkovac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

char	**sort_tab(char **tab)
{
	int		i;
	int		j;
	char	*swap;

	i = 0;
	j = i + 1;
	while (tab[i] && tab[j])
	{
		while (tab[j])
		{
			if (ft_atoi(tab[i]) > ft_atoi(tab[j]))
			{
				swap = tab[i];
				tab[i] = tab[j];
				tab[j] = swap;
			}
			j++;
		}
		i++;
		j = i + 1;
	}
	return (tab);
}

int	find_point(int size, t_nb **pile, int sign)
{
	int		i;
	t_nb	*tmp;
	char	**tab;
	int		mid;

	i = -1;
	tab = malloc(sizeof(*tab) * (size + 1));
	if (!tab)
		return (0);
	tmp = *pile;
	while (tmp != NULL)
	{
		tab[++i] = ft_itoa(tmp->value);
		tmp = tmp->next;
	}
	tab[++i] = NULL;
	sort_tab(tab);
	mid = ft_atoi(tab[size / sign]);
	free_tab(tab);
	return (mid);
}

void	push_all2(t_nb **lst_a, t_nb **lst_b)
{
	t_nb	*tmp_a;
	int		max;

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

void	push_all(t_nb **lst_a, t_nb **lst_b)
{
	t_nb	*tmp_a;
	int		max;
	int		med;
	int		size;

	size = lst_size(lst_a);
	med = find_point(size, lst_a, 2);
	tmp_a = *lst_a;
	max = ft_max(lst_a);
	while (lst_size(lst_a) > size / 2)
	{
		tmp_a = *lst_a;
		if (tmp_a->value > med)
			rotate(lst_a, "ra\n");
		else
		{	
			if (tmp_a->value == max)
				rotate(lst_a, "ra\n");
			else
				push(lst_a, lst_b, "pb\n");
		}
	}
	push_all2(lst_a, lst_b);
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
