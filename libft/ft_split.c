/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oeddamou <oeddamou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 08:20:19 by oeddamou          #+#    #+#             */
/*   Updated: 2024/11/03 07:47:41 by oeddamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_c_mot(char const *s, char c)
{
	int	i;
	int	mot;

	i = 0;
	mot = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			mot++;
		i++;
	}
	return (mot + 1);
}

static int	ft_m_mot(char const *s, char c, char **p)
{
	int	i;
	int	start;

	i = 0;
	while (s[i] && s[i] == c)
		i++;
	start = i;
	while (s[i] && s[i] != c)
		i++;
	*p = malloc(i - start + 1);
	if (*p == NULL)
		return (0);
	i = 0;
	while (s[start + i] && s[start + i] != c)
	{
		(*p)[i] = s[start + i];
		i++;
	}
	(*p)[i] = '\0';
	return (i + start);
}

char	**ft_split(char const *s, char c)
{
	char	**p;
	int		i;
	int		j;

	if (s == NULL)
		return (NULL);
	p = malloc (sizeof (char *) * ft_c_mot(s, c));
	if (!p)
		return (NULL);
	i = 0;
	j = 0;
	while (i < ft_c_mot(s, c) - 1)
	{
		j = j + ft_m_mot(s + j, c, &p[i]);
		if (!p[i])
		{
			while (i > 0)
				free(p[--i]);
			free (p);
			return (NULL);
		}
		i++;
	}
	p[i] = NULL;
	return (p);
}
