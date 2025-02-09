NAME = push_swap

MAN_DER = ./mandatory
SRC = $(MAN_DER)/moves.c $(MAN_DER)/push_swap.c $(MAN_DER)/utils.c $(MAN_DER)/valide.c
OBJ = $(SRC:.c=.o)

CHECKER = checker
CHE_DER = ./checker_bonus

SRC_BONUS = $(CHE_DER)/moves_bonus.c $(CHE_DER)/checker_bonus.c \
			 $(CHE_DER)/utils_bonus.c $(CHE_DER)/valide_bonus.c
OBJ_BONUS = $(SRC_BONUS:.c=.o)

LIBFT_DIR = ./libft_push_swap
LIBFT = $(LIBFT_DIR)/libft.a

%.o: %.c $(LIBFT_DIR)/libft.h $(CHE_DER)/checker_bonus.h
	cc -Wall -Wextra -Werror -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MAN_DER)/push_swap.h
	cc -Wall -Wextra -Werror $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)
################################################################
#***********relink:
# bonus: $(OBJ_BONUS) $(LIBFT) 
# 	cc -Wall -Wextra -Werror $(OBJ_BONUS) $(LIBFT) -o $(CHECKER)

#**********No relink:
bonus: $(CHECKER)

$(CHECKER): $(OBJ_BONUS) $(LIBFT) 
	cc -Wall -Wextra -Werror $(OBJ_BONUS) $(LIBFT) -o $(CHECKER)
################################################################

clean:
	make -C $(LIBFT_DIR) fclean
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME) $(CHECKER)

re: fclean all
