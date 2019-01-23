# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agottlie <agottlie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/08 15:24:16 by agottlie          #+#    #+#              #
#    Updated: 2019/01/23 08:37:12 by agottlie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = printf

FLAGS = -Wall -Wextra

SRC = ft_printf.c searchers.c validators.c print_functions.c

SRC2 = ft_printf2.c

OBJ = ft_printf.o searchers.o validators.o print_functions.o

OBJ2 = ft_printf2.o

INC = ft_printf.h

all: $(NAME)

$(NAME):
	# @make -C libft fclean && make -C libft
	@gcc $(FLAGS) -c $(SRC) -I $(INC)
	@gcc $(FLAGS) -Llibft -lft -I$(INC) -o $(NAME) $(OBJ)

f:
	@gcc $(FLAGS) -c $(SRC2) -I $(INC)
	@gcc $(FLAGS) -Llibft -lft -I$(INC) -o $(NAME) $(OBJ2)

ex:
	gcc -Wall -Wextra examples.c

clean:
	@/bin/rm -f $(OBJ2)
	# @make -C libft clean

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f fillit.a
	# @make -C libft fclean

re: fclean all
