/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oeddamou <oeddamou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:18:57 by oeddamou          #+#    #+#             */
/*   Updated: 2025/02/02 19:11:06 by oeddamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft_push_swap/libft.h"

int		ft_is_non_valide(char *str);
int		ft_check_arg(int ac, char **av);
int		ft_non_repete(t_list *lst);
t_list	*ft_to_lstnum(int ac, char **av);
void	ft_swap(t_list **stack);
void    ft_push(t_list **stack1, t_list **stack2);
void	ft_rotate(t_list **stack);
void    ft_rrotate(t_list **stack);
void	ft_free(char ***str);
void	ft_move(t_list **stack1, t_list **stack2, char *move);
int	ft_is_sorted(t_list *s_a, t_list *s_b);
int ft_is_ascending(t_list *s);
int ft_is_deascending(t_list *s);
int ft_best(t_list *s_a);
int ft_best2(t_list *s_a);
int	ft_find(t_list *s_a, int n);

#endif
