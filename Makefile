# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/28 15:39:16 by vguerand          #+#    #+#              #
#    Updated: 2018/03/08 15:20:23 by vguerand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = vguerand.filler
PATH_SRC = ./
PATH_OBJ = ./
PATH_INC = ./libft/includes/

CC = gcc
CFLAGS = -Wall -Wextra -Werror

HEAD = filler.h

SRC = ft_creat_lst.c ft_star.c ft_solv.c main.c ft_read.c ft_sqrt.c


OBJ = $(patsubst %.c,%.o,$(addprefix $(PATH_SRC), $(SRC)))

all: $(NAME)

$(NAME): $(OBJ) $(HEAD)
	make -C libft/
	$(CC) $(CFLAGS) -I $(PATH_INC) -c $(SRC)
	$(CC) -o $(NAME) $(OBJ) -L libft/ -lft
	mv $(NAME) ./players

.PHONY: clean fclean re all

clean:
	make -C libft/ clean
	/bin/rm -f $(OBJ)

fclean: clean
	make -C libft/ fclean
	/bin/rm -f players/$(NAME)

re: fclean all
