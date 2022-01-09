/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkovac <hkovac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 16:40:39 by hkovac            #+#    #+#             */
/*   Updated: 2022/01/09 21:33:02 by hkovac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

t_nb	*ft_min_t(t_nb **lst)
{
	t_nb	*tmp;
	t_nb	*save;

	save = NULL;
	tmp = *lst;
	save = tmp;
	tmp = tmp->next;
	while (tmp)
	{
		if (tmp->to_top_t < save->to_top_t)
			save = tmp;
		tmp = tmp->next;
	}
	return (save);
}

t_nb	*ft_min_value(t_nb **lst)
{
	t_nb	*tmp;
	t_nb	*save;

	save = NULL;
	tmp = *lst;
	save = tmp;
	tmp = tmp->next;
	while (tmp)
	{
		if (tmp->value < save->value)
			save = tmp;
		tmp = tmp->next;
	}
	return (save);
}

t_nb	*node_of_index(t_nb **lst, int idx)
{
	t_nb	*tmp;

	tmp = *lst;
	while (tmp->index != idx)
		tmp = tmp->next;
	return (tmp);
}
