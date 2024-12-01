# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/26 11:44:56 by rnovotny          #+#    #+#              #
#    Updated: 2024/12/01 13:19:45 by rnovotny         ###   ########.fr        #
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
		src/move_player.c \
		src/quit.c \
		src/raycast.c \
		src/render.c \
		src/rotate.c \
		src/texture.c \
		src/init/game.c \
		src/init/mlx.c \
		src/init/player.c \
		src/init/textures.c \
		src/minimap/draw_player_1.c \
		src/minimap/draw_player_2.c \
		src/minimap/render_image.c \
		src/minimap/render_map.c \
		src/gnl/get_next_line.c \
		src/gnl/get_next_line_utils.c \
		src/libft/ft_atoi.c \
		src/libft/ft_bzero.c \
		src/libft/ft_calloc.c \
		src/libft/ft_isdigit.c \
		src/libft/ft_isprint.c \
		src/libft/ft_itoa.c \
		src/libft/ft_split.c \
		src/libft/ft_strchr.c \
		src/libft/ft_strdup.c \
		src/libft/ft_strlen.c \
		src/libft/ft_strlcpy.c \
		src/libft/ft_memcpy.c\
		src/libft/ft_strncmp.c\
		src/libft/ft_isascii.c\
		src/check_parse/check_arg_mapinfo.c\
		src/check_parse/check_arg_stats.c\
		src/check_parse/check_arg.c\
		src/check_parse/check_walls.c\
		src/check_parse/game_before_beginning.c\
		src/check_parse/get_stats.c\
		src/check_parse/map_info_utils.c\
		src/check_parse/map_to_game.c

OBJ = $(SRC:.c=.o)

INC =	-I/usr/X11/include \
		-Imlx

MLX_LIB = mlx/

MLX_FLAGS = -Lmlx -lmlx -L/usr/X11/lib -lXext -lX11 

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLX_FLAGS) -lm -o $(NAME)

%.o: %.c
	@if [ ! -d "$(MLX_LIB)" ]; then \
	git clone https://github.com/42Paris/minilibx-linux.git $(MLX_LIB); \
	fi
	@if [ ! -f "$(MLX_LIB)/libmlx.a" ]; then \
	make -C $(MLX_LIB); \
	fi
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

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
