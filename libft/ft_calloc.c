/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oeddamou <oeddamou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 08:15:32 by oeddamou          #+#    #+#             */
/*   Updated: 2024/11/06 10:23:06 by oeddamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*p;
	size_t	i;

	i = 0;
	if (size != 0 && count > 18446744073709551615UL / size)
		return (NULL);
	p = malloc(size * count);
	if (p == NULL)
		return (NULL);
	while (i < count * size)
	{
		p[i] = '\0';
		i++;
	}
	return ((void *)p);
}
