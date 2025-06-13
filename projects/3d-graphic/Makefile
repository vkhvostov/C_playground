NAME = fdf
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR=libft
LIBFT_NAME=libft.a
LIBMLX_DIR=libmlx
LIBMLX_NAME=libmlx.a
SRCS = src/color.c \
		src/controls.c \
		src/draw.c \
		src/hex_to_int.c \
		src/line.c \
		src/main.c \
		src/parse_map_dimensions.c \
		src/parse_map.c \
		src/projection.c \
		src/utils.c
OBJS = $(SRCS:.c=.o)
HEADERS = includes/fdf.h
LIBS = -Llibft -lft -L./libmlx -lmlx -L/opt/X11/lib -lX11 -lXext -lm

LIBFT := $(LIBFT_DIR)/$(LIBFT_NAME)
LIBMLX := $(LIBMLX_DIR)/$(LIBMLX_NAME)

all: $(LIBFT) $(LIBMLX) $(NAME)

$(LIBFT):
	$(MAKE) bonus -C $(LIBFT_DIR)

$(LIBMLX):
	$(MAKE) -C $(LIBMLX_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(LIBMLX_DIR)
	rm -f $(OBJS)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all

norm:
	norminette -R CheckForbiddenSourceHeader $(SRCS)
	norminette -R CheckDefine $(HEADERS)

.PHONY: all clean fclean re norm
