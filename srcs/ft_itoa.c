/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkovac <hkovac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 18:11:05 by hkovac            #+#    #+#             */
/*   Updated: 2022/01/10 18:21:16 by hkovac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int	count_divide(long nb)
{
	int	size;

	size = 0;
	while (nb >= 10 || nb <= -10)
	{
		nb = nb / 10;
		size++;
	}
	if (nb < 0)
		size++;
	return (size + 1);
}

char	*ft_itoa(int n)
{
	int		size;
	char	*str;
	long	nb;

	str = NULL;
	nb = n;
	size = count_divide(nb);
	str = (char *) malloc(sizeof(*str) * (size + 1));
	if (str == NULL)
		return (NULL);
	str[size] = '\0';
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	while (nb >= 10)
	{
		str[size - 1] = nb % 10 + 48;
		size--;
		nb = nb / 10;
	}
	str[size - 1] = nb + 48;
	return (str);
}
