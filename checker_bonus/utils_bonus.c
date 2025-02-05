/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oeddamou <oeddamou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:18:43 by oeddamou          #+#    #+#             */
/*   Updated: 2025/02/05 17:57:48 by oeddamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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

void	ft_exit(t_list **s_a, t_list **s_b)
{
	ft_lstclear(s_a);
	ft_lstclear(s_b);
	exit(-1);
}
