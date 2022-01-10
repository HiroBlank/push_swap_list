/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkovac <hkovac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 16:09:08 by hkovac            #+#    #+#             */
/*   Updated: 2022/01/10 11:22:14 by hkovac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int	ft_check(char *str)
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

int	check_double(t_nb **lst, int size)
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

int	take_input(t_nb **lst, char **tab, int size)
{
	t_nb		*tmp;
	long long	content;

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
