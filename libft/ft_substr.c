/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oeddamou <oeddamou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 12:52:00 by oeddamou          #+#    #+#             */
/*   Updated: 2024/11/01 18:52:26 by oeddamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	str_len;

	if (!s)
		return (NULL);
	str_len = ft_strlen(s);
	if (start >= str_len)
	{
		p = malloc(1);
		if (p)
			p[0] = '\0';
		return (p);
	}
	if (len > str_len - start)
		len = str_len - start;
	p = malloc(len + 1);
	if (!p)
		return (NULL);
	ft_strlcpy(p, &s[start], len + 1);
	return (p);
}
