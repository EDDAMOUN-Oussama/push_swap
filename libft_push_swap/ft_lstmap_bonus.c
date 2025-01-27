/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oeddamou <oeddamou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 17:03:57 by oeddamou          #+#    #+#             */
/*   Updated: 2025/01/26 13:03:49 by oeddamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, int (*f)(int), void (*del)(int))
{
	t_list	*t;
	t_list	*l;
	int		c;

	if (!del || !*f || lst == NULL)
		return (NULL);
	l = NULL;
	while (lst)
	{
		c = f(lst->content);
		t = ft_lstnew(c);
		if (!t)
		{
			del(c);
			ft_lstclear(&l);
			return (NULL);
		}
		ft_lstadd_back(&l, t);
		lst = lst->next;
	}
	return (l);
}
