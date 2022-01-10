/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkovac <hkovac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 12:05:25 by hkovac            #+#    #+#             */
/*   Updated: 2022/01/10 14:20:27 by hkovac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	swap(t_nb **lst, char *str)
{
	t_nb	*tmp;
	t_nb	*save;

	tmp = (*lst)->next;
	save = (*lst);
	save->next = tmp->next;
	tmp->next = save;
	*lst = tmp;
	if (str)
		ft_putstr_fd(str, 1);
}

void	push(t_nb **lst1, t_nb **lst2, char *str)
{
	t_nb	*save;
	t_nb	*tmp;

	save = *lst1;
	tmp = *lst2;
	*lst1 = (*lst1)->next;
	save->next = tmp;
	*lst2 = save;
	if (str)
		ft_putstr_fd(str, 1);
}

void	rotate(t_nb **lst, char *str)
{
	t_nb	*tmp;
	t_nb	*save;

	tmp = *lst;
	save = *lst;
	*lst = (*lst)->next;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = save;
	save->next = NULL;
	if (str)
		ft_putstr_fd(str, 1);
}

void	r_rotate(t_nb **lst, char *str)
{
	t_nb	*tmp;
	t_nb	*save;

	tmp = *lst;
	while (tmp->next->next)
		tmp = tmp->next;
	save = tmp->next;
	tmp->next = NULL;
	save->next = *lst;
	*lst = save;
	if (str)
		ft_putstr_fd(str, 1);
}
