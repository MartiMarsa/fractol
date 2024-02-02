# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmarsa-s <mmarsa-s@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/29 12:42:13 by mmarsa-s          #+#    #+#              #
#    Updated: 2024/01/29 12:44:29 by mmarsa-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address
MLX_FLAGS = -framework OpenGL -framework AppKit

SRC = main.c utils.c init.c render.c mandelbrot.c julia.c burning_ship.c \
			events.c hooks.c
OBJ = $(SRC:.c=.o) 

SRC_MLX = ./mlx/libmlx.a
MAKE_MLX = make -C mlx --no-print-directory

%.o: %.c Makefile
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

all: make_mlx $(NAME)

make_mlx:
	$(MAKE_MLX)

$(NAME): $(OBJ) $(SRC_MLX)
	$(CC) $(CFLAGS) -Lmlx -lmlx $(MLX_FLAGS) $(^) -o $(NAME)

clean:
	rm -f $(OBJ) 
	$(MAKE) -C mlx clean --no-print-directory

fclean: clean
	rm -f $(NAME) 

re: fclean all

.PHONY: all clean fclean re 