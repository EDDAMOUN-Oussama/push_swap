/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oeddamou <oeddamou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 09:42:35 by oeddamou          #+#    #+#             */
/*   Updated: 2025/01/27 16:11:27 by oeddamou         ###   ########.fr       */
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

void	ft_move(t_list **stack1, t_list **stack2, char *str)
{
	if ()
}