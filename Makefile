NAME = so_long
SRC =	get_next_line.c \
		map_checker.c \
		so_long.c \
		print.c \
		moves.c \
		list.c
OBJ =	$(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror 


all: libft $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS)  $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Llibft -Ilibft -Imlx_linux -lXext -lX11 -lm -lz -o  $(NAME)

$(OBJ): %.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

libft:
	make all -C libft
clean:
	rm -f $(OBJ)
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re libft
