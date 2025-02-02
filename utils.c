/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oeddamou <oeddamou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:18:43 by oeddamou          #+#    #+#             */
/*   Updated: 2025/02/02 20:40:01 by oeddamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(char ***str)
{
	int	i;

	i = 0;
	while ((*str)[i])
	{
		free((*str)[i]);
		i++;
	}
	free((*str));
	(*str) = NULL;
}

int	ft_is_sorted(t_list *s_a, t_list *s_b)
{
	if (s_b)
		return (0);
	while (s_a->next)
	{
		if ((s_a->next)->content <= s_a->content)
		return (0);
		s_a = s_a->next;
	}
	return (1);
}

int ft_is_ascending(t_list *s)
{
	if (!s)
		return (0);
	while (s->next)
	{
		if ((s->content) > (s->next)->content)
			return (0);
		s = s->next;
	}
	return (1);
}

int ft_is_deascending(t_list *s)
{
	if (!s)
		return (0);	
	while (s->next)
	{
		if ((s->content) < (s->next)->content)
			return (0);
		s = s->next;
	}
	return (1);
}

int ft_best(t_list *s_a)
{
	t_list	*t;

	t = s_a;
	if (s_a)
	{
		t = s_a->next;
		while(t)
		{
			if (s_a->content < t->content)
				s_a = t;
			t = t->next;
		}
	}
	return (s_a->content);
}

int ft_best2(t_list *s_a)
{
	t_list	*t;

	t = s_a;
	if (s_a)
	{
		t = s_a->next;
		while(t)
		{
			if (s_a->content > t->content)
				s_a = t;
			t = t->next;
		}
	}
	return (s_a->content);
}

int	ft_find(t_list *s_a, int n)
{
	t_list *t;
	int		i;

	i = 0;
	t = s_a;
	while (t)
	{
		if (t->content == n)
			return (i);
		t = t->next;
		i++;
	}
	return (-1);
}
