/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oeddamou <oeddamou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 16:21:58 by oeddamou          #+#    #+#             */
/*   Updated: 2025/02/05 17:58:01 by oeddamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	ft_swap(t_list **stack)
{
	t_list	*next;

	if ((*stack) && (*stack)->next)
	{
		next = (*stack)->next;
		(*stack)->next = next->next;
		next->next = (*stack);
		(*stack) = next;
	}
	return (1);
}

int	ft_push(t_list **stack1, t_list **stack2)
{
	t_list	*node;

	node = *stack1;
	if (*stack1)
	{
		*stack1 = (*stack1)->next;
		ft_lstadd_front(stack2, node);
	}
	return (1);
}

int	ft_rotate(t_list **stack)
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
	return (1);
}

int	ft_rrotate(t_list **stack)
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
	return (1);
}

void	ft_move(t_list **stack1, t_list **stack2, char *move)
{
	int	c;

	c = 0;
	if (!ft_strncmp(move, "sa\n", 3) || !ft_strncmp(move, "ss\n", 3))
		c = ft_swap(stack1);
	if (!ft_strncmp(move, "sb\n", 3) || !ft_strncmp(move, "ss\n", 3))
		c = ft_swap(stack2);
	if (!ft_strncmp(move, "pa\n", 3))
		c = ft_push(stack2, stack1);
	if (!ft_strncmp(move, "pb\n", 3))
		c = ft_push(stack1, stack2);
	if (!ft_strncmp(move, "ra\n", 3) || !ft_strncmp(move, "rr\n", 3))
		c = ft_rotate(stack1);
	if (!ft_strncmp(move, "rb\n", 3) || !ft_strncmp(move, "rr\n", 3))
		c = ft_rotate(stack2);
	if (!ft_strncmp(move, "rra\n", 4) || !ft_strncmp(move, "rrr\n", 4))
		c = ft_rrotate(stack1);
	if (!ft_strncmp(move, "rrb\n", 4) || !ft_strncmp(move, "rrr\n", 4))
		c = ft_rrotate(stack2);
	if (c == 0)
	{
		ft_putstr_fd("Error\n", 2);
		free(move);
		ft_exit(stack1, stack2);
	}
}
