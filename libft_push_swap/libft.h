/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oeddamou <oeddamou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 09:57:48 by oeddamou          #+#    #+#             */
/*   Updated: 2025/02/05 11:25:36 by oeddamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 11
# endif

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				content;
	int				index;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(int content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstclear(t_list **lst);
char				**ft_split(char const *s, char c);
void				ft_putstr_fd(char *s, int fd);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
long				ft_atoi(const char *str);
int					ft_isdigit(int c);
char				*get_next_line(int fd);
char				*ft_read_line(int fd, char **line);
int					ft_strjoin(char **buf, char *r);
char				*ft_substr(char **r);
long				ft_strchr(char *p);
long				ft_strcpy(char *d, char *s, int c);

#endif
