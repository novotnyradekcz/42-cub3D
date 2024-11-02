# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/26 11:44:56 by rnovotny          #+#    #+#              #
#    Updated: 2024/11/02 10:33:38 by rnovotny         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = cc

CFLAGS = -Wall -Werror -Wextra

SRC = src/cub3d.c

OBJ = $(SRC:.c=.o)

MLX_LIB = mlx/

MLX_FLAGS = -Lmlx -lmlx -L/usr/X11/lib -lXext -lX11

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLX_FLAGS) -o $(NAME)

%.o: %.c
	@if [ ! -d "$(MLX_LIB)" ]; then \
	git clone https://github.com/42Paris/minilibx-linux.git $(MLX_LIB); \
	fi
	@make -C $(MLX_LIB)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@if [ -d "mlx" ]; then \
	make clean -C $(MLX_LIB); \
	fi
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(MLX_LIB)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
