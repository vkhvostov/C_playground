NAME = push_swap
CHECKER_NAME = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR=libft
LIBFT_NAME=libft.a
SRCS = push_swap.c \
		input_validation.c \
		sort_push_ops.c \
		sort_reverse_rotate_ops.c \
		sort_rotate_ops.c \
		sort_swap_ops.c \
		sort.c \
		lis.c \
		list_utils.c \
		sort_utils.c \
		utils.c \
		sort_algorithm.c \
		sort_algorithm2.c
CHECKER_SRCS = checker_input_validation.c \
		checker_instruction_validation.c \
		checker_main.c \
		checker_sort_push_ops.c \
		checker_sort_reverse_rotate_ops.c \
		checker_sort_rotate_ops.c \
		checker_sort_swap_ops.c \
		checker_utils.c \
		checker.c \
		get_next_line_utils.c \
		get_next_line.c
OBJS = $(SRCS:.c=.o)
CHECKER_OBJS = $(CHECKER_SRCS:.c=.o)
HEADERS = push_swap.h
CHECKER_HEADERS = checker.h

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_DIR)/$(LIBFT_NAME) -o $(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_NAME):
	$(MAKE) -C $(LIBFT_DIR)

bonus: $(CHECKER_NAME)

$(CHECKER_NAME): $(CHECKER_OBJS)
	$(CC) $(CFLAGS) $(CHECKER_OBJS) $(LIBFT_DIR)/$(LIBFT_NAME) -o $(CHECKER_NAME)

%.o: %.c $(CHECKER_HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(CHECKER_OBJS)

fclean: clean
	rm -f $(NAME) $(CHECKER_NAME)

re: fclean all

bonus_re: fclean bonus

norm:
	norminette -R CheckForbiddenSourceHeader $(SRCS) $(CHECKER_SRCS)
	norminette -R CheckDefine $(HEADERS) $(CHECKER_HEADERS)

.PHONY: all clean fclean re norm bonus bonus_re
