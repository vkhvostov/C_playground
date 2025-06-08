NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR=libft
LIBFT_NAME=libft.a
SRCS = src/file_utils.c \
		src/main.c \
		src/pipe_utils.c \
		src/pipex.c \
		src/process.c
OBJS = $(SRCS:.c=.o)
HEADERS = includes/pipex.h

all: $(LIBFT_NAME) $(NAME)

$(LIBFT_NAME):
	$(MAKE) bonus -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_DIR)/$(LIBFT_NAME) -o $(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	rm -f $(OBJS)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all

norm:
	norminette -R CheckForbiddenSourceHeader $(SRCS)
	norminette -R CheckDefine $(HEADERS)

.PHONY: all clean fclean re norm
