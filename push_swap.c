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

void affiche(int a)
{
	printf("%d  ", a);
}
int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char mot[4] ={'\0'};

	if (!ft_check_arg(ac, av))
		return (0);
	stack_a = ft_to_lstnum(ac, av);
	if (!stack_a || !ft_non_repete(stack_a))
		return (0);
	stack_b = NULL;
	printf ("the stack a:\n");
	ft_lstiter(stack_a, affiche);
	while (ft_strncmp(mot, "f", 1))
	{
		printf ("\n give me the move:  ");
		scanf("%s", mot);
		ft_move(&stack_a, &stack_b, mot);
		if (stack_a)
		{
			printf ("the stack a:\n");
			ft_lstiter(stack_a, affiche);
		}
		if (stack_b)
		{
			printf ("the stack b:\n");
			ft_lstiter(stack_b, affiche);
		}
	}	
	
}
