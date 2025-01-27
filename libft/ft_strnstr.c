/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oeddamou <oeddamou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 19:19:45 by oeddamou          #+#    #+#             */
/*   Updated: 2024/11/01 17:06:00 by oeddamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *fd, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (str == NULL && len == 0)
		return (NULL);
	if (fd[i] == '\0')
		return ((char *) str);
	while (str[i] && i < len)
	{
		j = 0;
		while (fd[j] == str[i + j] && fd[j] && str[i + j] && (i + j) < len)
			j++;
		if (fd[j] == '\0')
			return ((char *)(&str[i]));
		i++;
	}
	return (NULL);
}
