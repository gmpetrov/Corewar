#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/21 16:14:59 by gpetrov           #+#    #+#              #
#    Updated: 2014/01/28 22:29:46 by gpetrov          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		= asm
NAME2		= corewar
FILES		= assembleur.c
FILES_COR	= corewar.c list.c tools.c
SRCS		= $(addprefix src/, $(FILES))
SRCS_COR 	= $(addprefix src/, $(FILES_COR))
OBJS		= $(SRCS:src/%.c=.obj/%.o)
INC			= -I includes -I libft/includes
FLAGS		= # -Wall -Wextra -Werror
LIB			= -L libft -lft

all: $(NAME) $(NAME2)
$(NAME): $(OBJS)
	make -C libft
	cc $(FLAGS) $(SRCS) -o $(NAME) $(INC) $(LIB)
	cc $(FLAGS) $(SRCS_COR) -o $(NAME2) $(INC) $(LIB)
.obj/%.o: src/%.c
	mkdir -p .obj
	cc -c $< -o $@ $(FLAGS) $(INC)
gdb:
	make -C libft
	cc -g $(FLAGS) $(SRCS) -o $(NAME) $(INC) $(LIB)
	gdb $(NAME)
clean:
	rm -rf .obj
fclean: clean
	rm -f $(NAME)
	rm -f $(NAME2)
re: fclean all
