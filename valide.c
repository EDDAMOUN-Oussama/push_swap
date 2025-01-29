/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valide.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oeddamou <oeddamou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 16:21:58 by oeddamou          #+#    #+#             */
/*   Updated: 2025/01/29 13:39:28 by oeddamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_non_valide(char *str)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	if (!str || !*str)
		return (0);
	while (str[i])
	{
		if (str[i] != ' ')
			c = 1;
		i++;
	}
	if (!c)
		return (0);
	i = 0;
	while (str[i] && str[i + 1])
	{
		if (str[i] == '+' || str[i] == '-')
			if (!ft_isdigit(str[i + 1]) || (i > 0 && str[i -1] != ' '))
				return (0);
		i++;
	}
	return (1);
}

int	ft_zero(char *str, int j)
{
	int i;

	i = j;
	while (i && str[i] != ' ' && str[i]!= '-' && str[i] != '+')
		{
			if (str[i] != '0')
				return (0);
			i--;
		}
	return (1);
}

int	ft_check_arg(int ac, char **av)
{
	int	i;
	int	j;
	int	c;

	i = 1;
	while (i < ac)
	{
		j = ((c = 0), 0);
		if (!ft_is_non_valide(av[i]))
			return (ft_putstr_fd("Error\n", 2), 0);
		while (av[i][j])
		{
			if ((!ft_isdigit(av[i][j]) && av[i][j] != '+' && av[i][j] != '-'
					&& av[i][j] != ' ') || c == 10)
				return (ft_putstr_fd("Error\n", 2), 0);
			if (av[i][j] == ' ')
				c = 0;
			j++;
			if (c != 0 || !ft_zero(av[i], j))
			c++;
		}
		i++;
	}
	return (1);
}


t_list	*ft_to_lstnum(int ac, char **av)
{
	t_list	*num;
	char	**strs;
	long	n;
	int		i;
	int		j;

	num = ((i = 1), NULL);
	while (i < ac)
	{
		strs = ft_split(av[i], ' ');
		if (!strs)
			return (ft_putstr_fd("Error\n", 2), ft_lstclear(&num), NULL);
		j = 0;
		while (strs[j])
		{
			n = ft_atoi(strs[j]);
			if (n > 2147483647 || n < -2147483648)
				return (ft_putstr_fd("Error\n", 2), ft_free(&strs),
					ft_lstclear(&num), NULL);
			ft_lstadd_back(&num, ft_lstnew((int)n));
			j++;
		}
		i = ((ft_free(&strs)), i + 1);
	}
	return (num);
}

int	ft_non_repete(t_list *lst)
{
	t_list	*h;

	while (lst->next)
	{
		h = lst->next;
		while (h)
		{
			if (lst->content == h->content)
			{
				ft_putstr_fd("Error\n", 2);
				return (0);
			}
			h = h->next;
		}
		lst = lst->next;
	}
	return (1);
}
