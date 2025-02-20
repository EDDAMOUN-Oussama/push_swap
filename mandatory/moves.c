/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oeddamou <oeddamou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 16:21:58 by oeddamou          #+#    #+#             */
/*   Updated: 2025/02/05 11:12:00 by oeddamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list **stack)
{
	t_list	*next;

	if ((*stack) && (*stack)->next)
	{
		next = (*stack)->next;
		(*stack)->next = next->next;
		next->next = (*stack);
		(*stack) = next;
	}
}

void	ft_push(t_list **stack1, t_list **stack2)
{
	t_list	*node;

	node = *stack1;
	if (*stack1)
	{
		*stack1 = (*stack1)->next;
		ft_lstadd_front(stack2, node);
	}
}

void	ft_rotate(t_list **stack)
{
	t_list	*last;

	if ((*stack) && (*stack)->next)
	{
		last = *stack;
		while (last->next)
			last = last->next;
		last->next = *stack;
		*stack = (*stack)->next;
		(last->next)->next = NULL;
	}
}

void	ft_rrotate(t_list **stack)
{
	t_list	*bef_last;

	if ((*stack) && (*stack)->next)
	{
		bef_last = *stack;
		while ((bef_last->next)->next)
			bef_last = bef_last->next;
		(bef_last->next)->next = *stack;
		*stack = bef_last->next;
		bef_last->next = NULL;
	}
}

void	ft_move(t_list **stack1, t_list **stack2, char *move)
{
	if (!ft_strncmp(move, "sa", 2) || !ft_strncmp(move, "ss", 2))
		ft_swap(stack1);
	if (!ft_strncmp(move, "sb", 2) || !ft_strncmp(move, "ss", 2))
		ft_swap(stack2);
	if (!ft_strncmp(move, "pa", 2))
		ft_push(stack2, stack1);
	if (!ft_strncmp(move, "pb", 2))
		ft_push(stack1, stack2);
	if (!ft_strncmp(move, "ra", 2) || !ft_strncmp(move, "rr", 2))
		ft_rotate(stack1);
	if (!ft_strncmp(move, "rb", 2) || !ft_strncmp(move, "rr", 2))
		ft_rotate(stack2);
	if (!ft_strncmp(move, "rra", 3) || !ft_strncmp(move, "rrr", 3))
		ft_rrotate(stack1);
	if (!ft_strncmp(move, "rrb", 3) || !ft_strncmp(move, "rrr", 3))
		ft_rrotate(stack2);
	ft_putstr_fd(move, 1);
	ft_putstr_fd("\n", 1);
}
