/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oeddamou <oeddamou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 16:07:34 by oeddamou          #+#    #+#             */
/*   Updated: 2025/02/04 20:54:01 by oeddamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <math.h>
#include <stdio.h>

// void check_leaks()
// {
// 	system("leaks push_swap");
// }
void	sort_small(t_list **s_a, t_list **s_b)
{
	int n;

	n = ft_lstsize(*s_a);
	while (!ft_is_sorted(*s_a, NULL))
	{
		if ((*s_a)->index > ft_lstlast(*s_a)->index)
			ft_move(s_a, s_b, "rra");
		else if ((*s_a)->index > ((*s_a)->next)->index)
			ft_move(s_a, s_b, "sa");
		else if (n > 3)
		{
			ft_move(s_a, s_b, "pb");
		}
		else 
			ft_move(s_a, s_b, "rra");
	}
}

void	ft_sort(t_list **s_a, t_list **s_b)
{
	int	min_rang;
	int	max_rang;

	max_rang = ((min_rang = 0), ft_lstsize(*s_a) * 0.048 + 10);
	while (*s_a && !ft_is_sorted(*s_a, *s_b))
	{
		if ((*s_a)->index > ft_lstlast(*s_a)->index
			&& ft_lstlast(*s_a)->index < max_rang)
			ft_move(s_a, s_b, "rra");
		else if ((*s_a)->index > max_rang)
			ft_move(s_a, s_b, "ra");
		else if ((*s_a)->index < min_rang)
		{
			ft_move(s_a, s_b, "pb");
			if ((*s_a)->index > max_rang)
				ft_move(s_a, s_b, "rr");
			else
				ft_move(s_a, s_b, "rb");
			min_rang++;
			max_rang++;
		}
		else
		{
			if (ft_lstsize(*s_a) > 1
				&& (ft_lstlast(*s_a)->index < (*s_a)->index))
				ft_move(s_a, s_b, "rra");
			ft_move(s_a, s_b, "pb");
			if (ft_lstsize(*s_b) > 1 && ((*s_b)->index < ((*s_b)->next)->index))
				ft_move(s_a, s_b, "sb");
			min_rang++;
			max_rang++;
		}
	}
}

void	ft_index(t_list **s_a)
{
	t_list	*tmp1;
	int		i;
	int		min;

	if (!s_a || !*s_a)
		return ;
	i = 0;
	tmp1 = *s_a;
	while (tmp1)
		tmp1 = ((tmp1->index = -1), tmp1->next);
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
}

// void	ll(void)
// {
// 	system("leaks push_swap");
// }

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	// atexit(ll);
	if (!ft_check_arg(ac, av))
		return (0);
	stack_a = ft_to_lstnum(ac, av);
	if (!stack_a || !ft_non_repete(stack_a))
		return (ft_lstclear(&stack_a), 0);
	ft_index(&stack_a);
	stack_b = NULL;
	if (ft_lstsize(stack_a) <= 5)
		sort_small(&stack_a, &stack_b);
	if (!ft_is_sorted(stack_a, stack_b))
		ft_sort(&stack_a, &stack_b);
	while (stack_b)
	{
		if (ft_find(stack_b, ft_best(stack_b)) == 0)
			ft_move(&stack_a, &stack_b, "pa");
		else if (ft_find(stack_b, ft_best(stack_b)) <= ft_lstsize(stack_b) / 2)
			ft_move(&stack_a, &stack_b, "rb");
		else
			ft_move(&stack_a, &stack_b, "rrb");
	}
	ft_lstclear(&stack_a);
}
