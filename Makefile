# NAME = ./push_swap

# SRC = moves.c push_swap.c utils.c valide.c

# all: $(NAME)

# $(NAME): $(SRC) push_swap.h libft
# 	cc -Wall -Wextra -Wextra $(SRC) ./libft_push_swap/libft.a -o $(NAME)

# libft: ./libft_push_swap
# 	cd ./libft_push_swap
# 	make
# 	make clean
# 	cd ..

# clean:
# 	cd ./libft_push_swap
# 	make fclean
# 	cd ..

# fclean: clean
# 	rm -f $(NAME)

# re: fclean all


NAME = push_swap

SRC = moves.c push_swap.c utils.c valide.c
OBJ = $(SRC:.c=.o)

LIBFT_DIR = ./libft_push_swap
LIBFT = $(LIBFT_DIR)/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJ)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all
