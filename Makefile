# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yharwyn- <yharwyn-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/08 15:24:16 by agottlie          #+#    #+#              #
#    Updated: 2019/02/12 13:33:57 by yharwyn-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = printf

FLAGS = -Wall -Wextra 

FLAGS2 = -Wno-format-invalid-specifier -Wno-format -Wno-macro-redefined -Wno-implicitly-unsigned-literal

SRC = *.c

OBJ = *.o

INC = ft_printf.h


	# @make -C libft fclean && make -C libft
	# @make -C libft clean
	# @make -C libft fclean
all: $(NAME)

$(NAME):
	@gcc $(FLAGS) -c $(SRC) -I $(INC)
	@gcc $(FLAGS) -Llibft -lft -I$(INC) -o $(NAME) $(OBJ)
	@make clean

hi:
	@gcc $(FLAGS2) -c $(SRC) -I $(INC)
	@gcc $(FLAGS2) -Llibft -lft -I$(INC) -o $(NAME) $(OBJ)
	@make clean

ex:
	gcc -Wall -Wextra .examples.c

clean:
	@/bin/rm -f $(OBJ)
	@/bin/rm -f a.out

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
