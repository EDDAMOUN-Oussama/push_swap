/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oeddamou <oeddamou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 16:07:34 by oeddamou          #+#    #+#             */
/*   Updated: 2025/02/05 18:34:38 by oeddamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void check_leaks()
// {
// 	system("leaks push_swap");
// }
void	sort_small(t_list **s_a, t_list **s_b)
{
	int	n;

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

int	ft_compare(t_list **s_a, t_list **s_b, char c)
{
	if (c == 'a' && ft_lstsize(*s_a) > 1
		&& (*s_a)->index > ft_lstlast(*s_a)->index)
		return (1);
	if (c == 'b')
	{
		if (ft_compare(s_a, NULL, 'a'))
			ft_move(s_a, s_b, "rra");
		ft_move(s_a, s_b, "pb");
		if (ft_lstsize(*s_b) > 1 && ((*s_b)->index < ((*s_b)->next)->index))
			ft_move(s_a, s_b, "sb");
	}
	return (0);
}

void	ft_sort(t_list **s_a, t_list **s_b)
{
	int	min_rang;
	int	max_rang;

	max_rang = ((min_rang = 0), ft_lstsize(*s_a) * 0.048 + 10);
	while (*s_a && !ft_is_sorted(*s_a, *s_b))
		if (ft_lstlast(*s_a)->index < max_rang && ft_compare(s_a, NULL, 'a'))
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
		min_rang = ((max_rang++), min_rang + 1);
	}
	else
	{
		ft_compare(s_a, s_b, 'b');
		min_rang = ((max_rang++), min_rang + 1);
	}
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

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
