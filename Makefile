NAME = fdf

COMP = gcc

FLS_C = -c
FLS_O = -O2

LIBFT_NAME = libft

LIBFT_DIR = ./libft

L_LIBFT = -L $(LIBFT_DIR) -lft

I_HEADERS = -I get_next_line.h \
            -I ./libft/libft.h

MLX = -L ./minilibx_macos -lmlx -framework OpenGL -framework AppKit

SRCS = *.c

OBJS = $(SRCS:.c=.o)

all: $(LIBFT_NAME) $(NAME)

$(LIBFT_NAME):
	@make -C $(LIBFT_NAME)

$(NAME):
	$(COMP) $(FLS_C) $(SRCS)
	$(COMP) $(FLS_O) $(NAME) $(OBJS) $(MLX) $(L_LIBFT) $(I_HEADERS)

clean:
	@make clean -C libft
	@/bin/rm -f $(OBJS)

fclean: clean
	@make fclean -C libft
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re $(NAME) $(LIB_NAME)