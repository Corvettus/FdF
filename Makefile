NAME = fdf

COMP = gcc

FLS_C = -c -g
FLS_O = -O2 -o

LIBFT_NAME = libft

LIBFT_DIR = ./libft

L_LIBFT = -L $(LIBFT_DIR) -lft

I_HEADERS = -I get_next_line.h \
            -I ./libft/libft.h

#-L ./minilibx_macos -lmlx -framework OpenGL -framework AppKit

MLX =  -I /usr/local/include -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

SRCS = main.c read.c utils.c color.c get_next_line.c

OBJS = $(SRCS:.c=.o)

all: $(LIBFT_NAME) $(NAME)

$(LIBFT_NAME):
	make -C $(LIBFT_NAME)

$(NAME):
	$(COMP) $(FLS_C) $(SRCS)
	$(COMP) $(FLS_O) $(NAME) $(OBJS) $(I_HEADERS) $(MLX) $(L_LIBFT)

clean:
	@make clean -C libft
	@/bin/rm -f $(OBJS)

fclean: clean
	@make fclean -C libft
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re $(NAME) $(LIBFT_NAME)