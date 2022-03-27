NAME = printf

FLAGS = -Wall -Wextra 

FLAGS2 = -Wno-format-invalid-specifier -Wno-format -Wno-macro-redefined -Wno-implicitly-unsigned-literal

SRC = *.c

OBJ = *.o

INC = ft_printf.h


	# @make -C libft clean
	# @make -C libft fclean
all: $(NAME)

$(NAME):
	# @make -C libft fclean && make -C libft
	@gcc $(FLAGS) -c $(SRC) -I $(INC)
	@gcc $(FLAGS) -Llibft -lft -I$(INC) -o $(NAME) $(OBJ)
	@make clean

norme:
	norminette $(SRC)

ex:
	gcc -Wall -Wextra examples/.examples.c

clean:
	@/bin/rm -f $(OBJ)
	@/bin/rm -f a.out

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
