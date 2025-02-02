/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oeddamou <oeddamou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 16:07:34 by oeddamou          #+#    #+#             */
/*   Updated: 2025/02/02 21:11:35 by oeddamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void  add_nomb(int *n)
{
	*n = *n - 10000000;
}
void affiche(int *a)
{
	printf("%d  ", *a);
}
void	ft_sort(t_list **s_a, t_list **s_b)
{

	int min_rang;
	int max_rang;

	min_rang = 0;
	max_rang = ft_lstsize(*s_a) * 0.048 + 10;
	while (*s_a)
	{
		if ((*s_a)->index > max_rang)
			{
				if (ft_lstlast(*s_a)->index < max_rang)
					ft_move(s_a, s_b, "rra");
				// else if (ft_lstsize(*s_a) > 1 && ((*s_a)->next->index < max_rang))
				// ft_move(s_a, s_b, "sa");
				else
				ft_move(s_a, s_b, "ra");
			}
		else if ((*s_a)->index < min_rang)
			{
					
				ft_move(s_a, s_b, "pb");
				// if (ft_lstsize(*s_b) > 1 && ((*s_b)->index > ft_lstlast(*s_b)->index))
				// {
				// ft_move(s_a, s_b, "rrb");
				// ft_move(s_a, s_b, "sb");
				// ft_move(s_a, s_b, "rb");
					
				// }
				ft_move(s_a, s_b, "rb");
				
			}
		else 
		{
			if (ft_lstsize(*s_a) > 1 && (ft_lstlast(*s_a)->index < (*s_a)->index))
				ft_move(s_a, s_b, "rra");
			ft_move(s_a, s_b, "pb");
			 if (ft_lstsize(*s_b) > 1 && ((*s_b)->index < ((*s_b)->next)->index))
			 	ft_move(s_a, s_b, "sb");
			min_rang++;
			max_rang++;
		}
	}
	while (*s_b)
	{

		if (ft_find(*s_b, ft_best(*s_b)) == 0)
			ft_move(s_a, s_b, "pa");
		else if (ft_find(*s_b, ft_best(*s_b)) <= ft_lstsize(*s_b) / 2)
			ft_move(s_a, s_b, "rb");
		else 
			ft_move(s_a, s_b, "rrb");
	}
	
	// while (!ft_is_sorted(*s_a, *s_b))
	// {
		// printf ("the stack a: ");
		// ft_lstiter(*s_a, affiche);
		// printf ("\nthe stack b: ");
		// ft_lstiter(*s_b, affiche);
		// printf ("\n---------------\n");
		// if (((*s_a)->content > ((*s_a)->next)->content))
		// 	ft_move(s_a, s_b, "sa");
		// 	ft_move(s_a, s_b, "ra");
		// 	continue;
		// if ((ft_is_ascending(*s_a) && ft_is_deascending(*s_b)) || !*s_a)
		// 	{
		// 		while (!*s_a || (*s_b && (*s_a)->content > (*s_b)->content))
		// 			ft_move(s_a, s_b, "pa");
		// 		if (*s_b)
		// 			ft_move(s_a, s_b, "pb");
		// 		ft_move(s_a, s_b, "sb");
				
		// 	}
		// else if (!ft_is_deascending(*s_b))
		// {
		// 	if ((ft_lstsize(*s_b) > 1)
		// 		&& (*s_b)->content > ((*s_b)->next)->content)
		// 		ft_move(s_a, s_b, "sb");

		// }
	// 	else if ((*s_a)->content > (ft_lstlast(*s_a))->content)
	// 		ft_move(s_a, s_b, "rra");
	// 	else if ((ft_lstsize(*s_a) > 1)
	// 		&& (*s_a)->content > ((*s_a)->next)->content)
	// 		ft_move(s_a, s_b, "sa");
	// 	else if (!*s_b || (ft_lstsize(*s_a) > 1
	// 			&& (*s_a)->content > (*s_b)->content))
	// 		ft_move(s_a, s_b, "pb");
	// 	else if ((ft_lstsize(*s_b) > 1)
	// 		&& (*s_b)->content < ((*s_b)->next)->content)
	// 		ft_move(s_a, s_b, "sb");
	// 	else if ((*s_b)->content < (ft_lstlast(*s_b))->content)
	// 		ft_move(s_a, s_b, "rb");
	// 	else if ((*s_a)->content < (ft_lstlast(*s_b))->content)
	// 		{
	// 			ft_move(s_a, s_b, "pb");
	// 			ft_move(s_a, s_b, "rb");
	// 		}
	// 	else if (*s_a && (*s_a)->content == ft_best(*s_a))
	// 			ft_move(s_a, s_b, "pb");
	// 	else if (*s_a && ft_find(*s_a, ft_best(*s_a)) <= ft_lstsize(*s_a) / 2)
	// 			while ((*s_a)->content != ft_best(*s_a))
	// 			ft_move(s_a, s_b, "ra");
	// 	else
	// 		while (*s_a && (*s_a)->content != ft_best(*s_a))
	// 		ft_move(s_a, s_b, "rra");
	// }
	// while (!ft_is_sorted(*s_a, *s_b))
	// {
	// 	if (ft_is_ascending(*s_a) && ft_is_deascending(*s_b))
	// 		ft_move(s_a, s_b, "pa");
	// 	else if ((*s_a)->content > (ft_lstlast(*s_a))->content)
	// 		ft_move(s_a, s_b, "ra");
	// 	else if ((ft_lstsize(*s_a) > 1) &&(*s_a)->content > ((*s_a)->next)->content)
	// 		ft_move(s_a, s_b, "sa");
	// 	else if (!*s_b || (ft_lstsize(*s_a) > 1 && (*s_a)->content > (*s_b)->content))
	// 		ft_move(s_a, s_b, "pb");
	// 		else if (!ft_is_ascending(*s_b) && (*s_b)->content > ((*s_b)->next)->content)
	// 			ft_move(s_a, s_b, "sb");
	// 		else 
	// 		ft_move(s_a, s_b, "pa");
				
	// }
}
void ft_index(t_list **s_a)
{
	t_list *tmp1;
	// t_list *tmp2;
	int i;
	int min;

	i = 0;
	if (!s_a || !*s_a)
		return ;
	tmp1 = *s_a;
	while (tmp1)
	{
		tmp1->index = -1;
		tmp1 = tmp1->next;
	}
	i = 0;
	while (i < ft_lstsize(*s_a))
	{
		min = ft_best(*s_a);
		tmp1 = (*s_a);
		while (tmp1)
		{
			if (min > tmp1->content && tmp1->index == -1)
				min = tmp1->content;
			tmp1 = tmp1->next;
		}
		tmp1 = *s_a;
		while (tmp1->content != min)
			tmp1 = tmp1->next;
		tmp1->index = i++;
	}

	// while (tmp1)
	// {
	// 	tmp2 = *s_a;
	// 	while (tmp2->next)
	// 	{
	// 		if (tmp1->content < tmp2->content && tmp1->index > tmp2->index)
	// 		{
	// 			i = tmp1->index;
	// 			tmp1->index = tmp2->index;
	// 			tmp2->index = i;
	// 		}
	// 		tmp2 = tmp2->next;
	// 	}
	// 	tmp1 = tmp1->next;
	// }
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	// char mot[4] ={'\0'};
	if (!ft_check_arg(ac, av))
		return (0);
	stack_a = ft_to_lstnum(ac, av);
	if (!stack_a || !ft_non_repete(stack_a))
		return (0);
	// ft_lstiter(stack_a, affiche);
	// printf("\n");
	ft_index(&stack_a);
	stack_b = NULL;

	// printf ("the stack a:\n");
	// ft_lstiter(stack_a, add_nomb);
	// while (ft_strncmp(mot, "f", 1))
	// {
	// 	printf ("\n--------------------------------------------\n give me the move:  ");
	// 	scanf("%s", mot);
	// 	ft_move(&stack_a, &stack_b, mot);
	// 	if (stack_a)
	// 	{
	// 		printf ("the stack a:\n");
	// 		ft_lstiter(stack_a, affiche);
	// 	}
	// 	if (stack_b)
	// 	{
	// 		printf ("the stack b:\n");
	// 		ft_lstiter(stack_b, affiche);
	// 	}
	// }	
	// printf("\nthe movse:\n");
	ft_sort(&stack_a, &stack_b);
	// printf ("the stack a:\n");
	
	// while (stack_a->next)
	// while (stack_a)
	// {
	// 	// if (stack_a->content > stack_a->next->content)
	// 		// printf("\n ERROR IN: \n");
	// 	printf("%d[%d]\n", stack_a->content, stack_a->index);
	// 	stack_a = stack_a->next;
	// }
	
	// ft_lstiter(stack_a, affiche);
	
}
