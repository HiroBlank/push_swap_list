/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkovac <hkovac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 11:44:20 by hkovac            #+#    #+#             */
/*   Updated: 2022/01/06 16:06:29 by hkovac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incldue.h"
#include <libc.h>

int		ft_error(int rtn)
{
	ft_putstr_fd("Error\n", 2);
	return (rtn);
}

int		ft_check(char *str)
{
	if (!str)
		return (0);
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int		check_double(t_nb **lst, int size)
{
	t_nb	*tmp1;
	t_nb	*tmp2;
	int		i;

	tmp1 = *lst;
	i = 0;
	while (tmp1)
	{
		tmp2 = *lst;
		while (tmp2)
		{
			if (tmp1->value == tmp2->value)
				i++;
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;	
	}
	if (i > size)
		return (1);
	return (0);
}

int		take_input(t_nb **lst, char **tab, int size)
{
	t_nb	*tmp;
	int		content;

	tmp = *lst;
	while (*tab)
	{
		if (!ft_check(*tab))
			return (0);
		content = ft_atoi(*tab);
		add_node_back(lst, content);
		if (content < -2147483648 || content > 2147483647)
			return (del_list(lst));
		tab++;
	}
	tmp = *lst;
	if (check_double(lst, size))
		return (0);
	return (1);
}

int		push_swap(int size, char **tab)
{
	t_nb	*lst;
	
	lst = NULL;
	if (!take_input(&lst, tab, size))
		return (0);
	return (1);
}

int		main(int ac, char **av)
{
	// if (ac == 2)// split ou rien
	// printf("a\n");
	if (ac > 2)
		if (!push_swap(ac - 1, av + 1))
			return (ft_error(1));
	return (0);
}

// int main(void)
// {
// 	t_nb *lst;
// 	lst = new_node(1);
// 	add_node_back(&lst, 2);
// 	add_node_back(&lst, 3);
// 	add_node_back(&lst, 4);
// 	while (lst)
// 	{
// 		printf("%d\n", lst->value);
// 		lst = lst->next;
// 	}
// 	return (0);
// }