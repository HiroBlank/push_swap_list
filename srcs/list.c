/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkovac <hkovac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 12:13:49 by hkovac            #+#    #+#             */
/*   Updated: 2022/01/10 11:00:36 by hkovac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

t_nb	*new_node(int content)
{
	t_nb	*new;

	new = malloc(sizeof (t_nb));
	if (!new)
		return (NULL);
	new->value = content;
	new->to_top = 0;
	new->next = NULL;
	return (new);
}

void	add_node_back(t_nb **first, int content)
{
	t_nb	*tmp;

	if (!*first)
		*first = new_node(content);
	else
	{	
		tmp = *first;
		while (tmp->next != NULL)
			tmp = (tmp)->next;
		tmp->next = new_node(content);
	}
}

int	del_list(t_nb **lst)
{
	t_nb	*tmp;

	if (lst)
	{
		while (*lst)
		{
			tmp = (*lst)->next;
			free(*lst);
			*lst = tmp;
		}
	}
	return (0);
}

int	lst_size(t_nb **lst)
{
	t_nb	*tmp;
	int		i;

	tmp = *lst;
	i = 1;
	if (!*lst)
		return (0);
	while (tmp->next)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
