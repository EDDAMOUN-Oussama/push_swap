NAME = libft.a
SRC= ft_atoi.c ft_isdigit.c ft_lstadd_back.c ft_lstadd_front.c \
 	 ft_lstclear.c ft_lstlast.c ft_lstnew.c ft_lstsize.c \
 	 ft_putstr_fd.c ft_split.c ft_strncmp.c
OBJ= $(SRC:.c=.o)
all: $(NAME)

$(NAME): $(OBJ)
	ar -rc $(NAME) $(OBJ)

%.o: %.c libft.h
	cc -Wall -Wextra -Werror -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f
	
fclean: clean
	rm -f $(NAME)

re: fclean all