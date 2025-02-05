/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oeddamou <oeddamou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 10:42:53 by oeddamou          #+#    #+#             */
/*   Updated: 2025/02/05 18:41:46 by oeddamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	*move;

	if (!ft_check_arg(ac, av))
		return (0);
	stack_a = ft_to_lstnum(ac, av);
	if (!stack_a || !ft_non_repete(stack_a))
		return (ft_lstclear(&stack_a), 0);
	stack_b = NULL;
	move = get_next_line(0);
	while (move)
	{
		ft_move(&stack_a, &stack_b, move);
		free(move);
		move = get_next_line(0);
	}
	free(move);
	if (ft_is_sorted(stack_a, stack_b))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
	return (0);
}
