# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/26 11:44:56 by rnovotny          #+#    #+#              #
#    Updated: 2024/11/09 10:47:07 by rnovotny         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = cc

CFLAGS = -Wall -Werror -Wextra

SRC =	src/cub3d.c \
		src/check_move.c \
		src/error.c \
		src/free.c \
		src/handle_input.c \
		src/init.c \
		src/move_player.c \
		src/parse.c \
		src/quit.c \
		src/raycasting.c \
		src/rendering.c \
		src/rotate.c \
		src/testuring.c \
		src/init/data.c \
		src/init/mlx.c \
		src/init/player.c \
		src/init/textures.c \
		src/minimap/render_image.c \
		src/minimap/render_map.c \
		src/parsing/check_args.c \
		src/parsing/check_map_borders.c \
		src/parsing/check_map.c \
		src/parsing/check_textures.c \
		src/parsing/create_game_map.c \
		src/parsing/fill_color_textures.c \
		src/parsing/get_file_data.c \
		src/parsing/parse_data.c \
		src/parsing/parsing_utils.c \
		src/gnl/get_next_line.c \
		src/gnl/get_next_line_utils.c \
		src/libft/ft_itoa.c \
		src/libft/ft_strlen.c

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
