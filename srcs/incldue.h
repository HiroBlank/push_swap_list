/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   incldue.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkovac <hkovac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 11:44:23 by hkovac            #+#    #+#             */
/*   Updated: 2022/01/06 15:09:38 by hkovac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLDUE_H
# define INCLDUE_H

# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_nb
{
	int			value;
	int			to_top;
	struct s_nb	*next;
} t_nb;

/*list.c*/
t_nb	*new_node(int content);
void	add_node_back(t_nb **first, int content);
int		del_list(t_nb **lst);


#endif