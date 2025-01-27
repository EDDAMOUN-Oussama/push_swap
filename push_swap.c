/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oeddamou <oeddamou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 16:07:34 by oeddamou          #+#    #+#             */
/*   Updated: 2025/01/27 15:54:56 by oeddamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>


int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*h;
	t_list	*stack_b;

	if (!ft_check_arg(ac, av))
		return (0);
	stack_a = ft_to_lstnum(ac, av);
	if (!stack_a || !ft_non_repete(stack_a))
		return (0);
	stack_b = NULL;
	h = stack_a;
	while (h)
	{
		printf("%d\n", h->content);
		h = h->next;
	}
	ft_rotate(&stack_a);
	printf("after the rrotate:\nstack a:\n");
	h = stack_a;
	while (h)
	{
		printf("%d\n", h->content);
		h = h->next;
	}
	printf("stack b:\n");
	h = stack_b;
	while (h)
	{
		printf("%d\n", h->content);
		h = h->next;
	}
	
}
