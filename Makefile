NAME =		push_swap

SRC_DIR = 	srcs
OBJS_DIR =	objs

CC =		clang -g
FLAGS_CC =	-Wall -Wextra -Werror -I ./$(NAME).h

SRCS =		$(SRC_DIR)/push_swap.c $(SRC_DIR)/ft_isdigit.c $(SRC_DIR)/ft_atoi.c \
			$(SRC_DIR)/operations.c $(SRC_DIR)/init.c $(SRC_DIR)/error.c \
			$(SRC_DIR)/sort.c $(SRC_DIR)/large.c $(SRC_DIR)/sort_five.c \
			$(SRC_DIR)/ft_split.c $(SRC_DIR)/ft_calloc.c \
			$(SRC_DIR)/operations_cont.c $(SRC_DIR)/large_part_two.c \
			$(SRC_DIR)/large_part_three.c $(SRC_DIR)/large_part_four.c \
			$(SRC_DIR)/check.c

OBJS =		$(patsubst $(SRC_DIR)%.c, $(OBJS_DIR)%.o, $(SRCS)) #subst in directory

RM =		/bin/rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS_CC) $(OBJS)-o $@

$(OBJS_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJS_DIR)
	$(CC) $(FLAGS_CC) -c $< -o $@

clean:
	$(RM) $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

run: re
	./$(NAME) $(ARGS)

.PONY: all clean fclean re
