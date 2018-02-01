NAME = graph
PATH_SRC = ./
PATH_OBJ = ./
PATH_INC = ../libft/includes/

CC = gcc
CFLAGS =  -Wall -Wextra -Werror

HEAD = bonus.h

SRC = mlx_pixel_put_to_image.c main.c ft_read.c ft_exit.c

OBJ = $(patsubst %.c,%.o,$(addprefix $(PATH_SRC), $(SRC)))

all: $(NAME)

$(NAME): $(OBJ) $(HEAD)
	make -C ../libft/
	$(CC) $(CFLAGS) -I $(PATH_INC) -c $(SRC)
	$(CC) -o $(NAME) $(OBJ) -L ../libft/ -lft -lmlx -framework OpenGL -framework AppKit
	mv $(NAME) ../.

.PHONY: clean fclean re all

clean:
	make -C ../libft/ clean
	/bin/rm -f $(OBJ)

fclean: clean
	make -C libft/ fclean
	/bin/rm -f $(NAME)

re: fclean all
