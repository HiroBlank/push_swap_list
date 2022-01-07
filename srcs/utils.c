/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkovac <hkovac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 16:09:44 by hkovac            #+#    #+#             */
/*   Updated: 2022/01/07 11:51:18 by hkovac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int		ft_error(int rtn)
{
	ft_putstr_fd("Error\n", 2);
	return (rtn);
}

char	**ft_parse(char **av)
{
	char	**tab;
	
	tab = ft_split(*av, ' ');
	if (!tab || ft_count(tab) < 1)
	{
		free_tab(tab);
		return (NULL);
	}
	return (tab);
}

void	free_tab(char **tab)
{
	if (!tab)
		return ;
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int		ft_count(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}