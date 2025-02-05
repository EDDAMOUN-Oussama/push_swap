/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oeddamou <oeddamou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 10:43:34 by oeddamou          #+#    #+#             */
/*   Updated: 2025/02/05 12:47:30 by oeddamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "../libft_push_swap/libft.h"

int		ft_is_non_valide(char *str);
int		ft_check_arg(int ac, char **av);
int		ft_non_repete(t_list *lst);
t_list	*ft_to_lstnum(int ac, char **av);
int		ft_swap(t_list **stack);
int		ft_push(t_list **stack1, t_list **stack2);
int		ft_rotate(t_list **stack);
int		ft_rrotate(t_list **stack);
void	ft_free(char ***str);
void	ft_move(t_list **stack1, t_list **stack2, char *move);
int		ft_is_sorted(t_list *s_a, t_list *s_b);
void	ft_exit(t_list **s_a, t_list **s_b);

#endif