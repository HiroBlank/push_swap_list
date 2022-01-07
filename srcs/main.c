/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkovac <hkovac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 11:44:20 by hkovac            #+#    #+#             */
/*   Updated: 2022/01/07 15:47:20 by hkovac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"
	/*
	push(&lst_a, &lst_b, "pb\n");
	push(&lst_a, &lst_b, "pb\n");
	push(&lst_a, &lst_b, "pb\n");
	index_list(&lst_a);
	index_list(&lst_b);
	move_list(&lst_a);
	move_list(&lst_b);
	move_list_t(&lst_a, &lst_b);
	index_link_list(&lst_a, &lst_b);
	print_stack(&lst_a);//
	print_stack(&lst_b);//
	*/

int		push_swap(int size, char **tab)
{
	t_nb	*lst_a;
	t_nb	*lst_b;
	
	lst_a = NULL;
	lst_b = NULL;
	if (!take_input(&lst_a, tab, size))
		return (0);
	del_list(&lst_a);
	del_list(&lst_b);
	return (1);
}

int		main(int ac, char **av)
{
	char	**tab;
	
	if (ac == 2)// split ou rien
	{
		tab = ft_parse(av + 1);
		if (!tab)
			return (ft_error(1));
		else
		{
			if (!push_swap(ft_count(tab), tab))
			{
				free_tab(tab);
				return (ft_error(1));
			}
			free_tab(tab);
		}
	}
	if (ac > 2)
		if (!push_swap(ac - 1, av + 1))
			return (ft_error(1));
	return (0);
}