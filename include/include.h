/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkovac <hkovac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 11:44:23 by hkovac            #+#    #+#             */
/*   Updated: 2022/01/10 17:56:09 by hkovac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDE_H
# define INCLUDE_H

# define ROT 42
# define RROT 43

# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_nb
{
	int			value;
	int			to_top;
	int			to_top_t;
	int			index;
	int			index_link;
	int			rot;
	struct s_nb	*next;
}	t_nb;

/*main.c*/
int		push_swap(int size, char **tab);
/*list.c*/
t_nb	*new_node(int content);
void	add_node_back(t_nb **first, int content);
int		del_list(t_nb **lst);
int		lst_size(t_nb **lst);
/*check_input.c*/
int		ft_check(char *str);
int		check_double(t_nb **lst, int size);
int		take_input(t_nb **lst, char **tab, int size);
/*utils.c*/
int		ft_error(int rtn);
char	**ft_parse(char **av);
void	free_tab(char **tab);
int		ft_count(char **tab);
void	all_specs(t_nb **lst_a, t_nb **lst_b);
/*move.c*/
void	swap(t_nb **lst, char *str);
void	push(t_nb **lst1, t_nb **lst2, char *str);
void	rotate(t_nb **lst, char *str);
void	r_rotate(t_nb **lst, char *str);
/*spec_list.c*/
void	index_list(t_nb **lst);
void	index_link_list(t_nb **lst_a, t_nb **lst_b);
void	move_list(t_nb **lst);
void	move_list_t(t_nb **lst_a, t_nb **lst_b);
/*algo.c*/
void	algo(t_nb **lst_a, t_nb **lst_b);
int		find_point(int size, t_nb **pile, int sign);
char	**sort_tab(char **tab);
/*utils_algo.c*/
t_nb	*ft_min_t(t_nb **lst);
t_nb	*node_of_index(t_nb **lst, int idx);
t_nb	*ft_min_value(t_nb **lst);
/*utils2_algo.c*/
int		to_top_b(t_nb **lst);
void	to_top_a(t_nb **lst, int idx);
int		ft_max(t_nb **lst);
int		ft_sort(t_nb **lst);
/*algo_10.c*/
int		ft_sort_simple(t_nb **lst, int size);
void	algo_10(t_nb **lst_a, t_nb **lst_b);
/*itoa.c*/
char	*ft_itoa(int n);

#endif