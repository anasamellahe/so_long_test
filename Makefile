NAME = so_long
SRC =	src/get_next_line.c \
		src/map_checker.c \
		src/so_long.c \
		src/print.c \
		src/moves.c \
		src/list.c\
		src/list_2.c\
		src/print_2.c\
		src/utils.c
OBJ =	$(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror 


all: libft $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS)  $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Llibft -lft -Imlx_linux -lXext -lX11 -lm -lz -o  $(NAME)

$(OBJ): %.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

libft:
	@make  all -s -C libft
clean:
	rm -f $(OBJ)
	@make  clean -s -Clibft

fclean: clean
	rm -f $(NAME)
	@make  fclean -s -C libft 

re: fclean all

.PHONY: all clean fclean re libft
