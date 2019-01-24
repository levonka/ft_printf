# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agottlie <agottlie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/08 15:24:16 by agottlie          #+#    #+#              #
#    Updated: 2019/01/24 08:59:51 by agottlie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = printf

FLAGS = -Wall -Wextra

SRC = *.c

OBJ = *.o

INC = ft_printf.h

all: $(NAME)

$(NAME):
	# @make -C libft fclean && make -C libft
	@gcc $(FLAGS) -c $(SRC) -I $(INC)
	@gcc $(FLAGS) -Llibft -lft -I$(INC) -o $(NAME) $(OBJ)
	@make clean

ex:
	gcc -Wall -Wextra .examples.c

clean:
	@/bin/rm -f $(OBJ)
	@/bin/rm -f a.out
	# @make -C libft clean

fclean: clean
	@/bin/rm -f $(NAME)
	# @make -C libft fclean

re: fclean all
