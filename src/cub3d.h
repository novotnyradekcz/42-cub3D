/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 12:08:04 by rnovotny          #+#    #+#             */
/*   Updated: 2024/11/09 12:54:48 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx/mlx.h"
# include "libft/libft.h"
# include "gnl/get_next_line.h"
# include <errno.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <X11/keysym.h>
# include <X11/X.h>

# define WIN_WIDTH 640
# define WIN_HEIGHT 480

# define TEX_SIZE 64

# define MOVESPEED 0.0125
# define ROTSPEED 0.015

# define MMAP_PIXEL_SIZE 128
# define MMAP_VIEW_DIST 4
# define MMAP_COLOR_PLAYER 0x00FF00
# define MMAP_COLOR_WALL 0x808080
# define MMAP_COLOR_FLOOR 0xE6E6E6
# define MMAP_COLOR_SPACE 0x404040

# define DIST_EDGE_MOUSE_WRAP 20

enum e_output
{
	SUCCESS = 0,
	FAILURE = 1,
	ERR = 2,
	BREAK = 3,
	CONTINUE = 4
};

enum e_texture_index
{
	NORTH = 0,
	SOUTH = 1,
	EAST = 2,
	WEST = 3
};

typedef struct s_img
{
	void	*img;
	int		*addr;
	int		pixel_bits;
	int		size_line;
	int		endian;
}	t_img;

typedef struct s_texinfo
{
	char			*north;
	char			*south;
	char			*west;
	char			*east;
	int				*floor;
	int				*ceiling;
	unsigned long	hex_floor;
	unsigned long	hex_ceiling;
	int				size;
	int				index;
	double			step;
	double			pos;
	int				x;
	int				y;
}	t_texinfo;

typedef struct s_minimap
{
	char	**map;
	t_img	*img;
	int		size;
	int		offset_x;
	int		offset_y;
	int		view_dist;
	int		tile_size;
}	t_minimap;

typedef struct s_mapinfo
{
	int			fd;
	int			line_count;
	char		*path;
	char		**file;
	int			height;
	int			width;
	int			index_end_of_map;
}	t_mapinfo;

typedef struct s_ray
{
	double	camera_x;
	double	dir_x;
	double	dir_y;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	double	sidedist_x;
	double	sidedist_y;
	double	deltadist_x;
	double	deltadist_y;
	double	wall_dist;
	double	wall_x;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
}	t_ray;

typedef struct s_player
{
	char	dir;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	int		has_moved;
	int		move_x;
	int		move_y;
	int		rotate;
}	t_player;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	int			win_height;
	int			win_width;
	t_mapinfo	mapinfo;
	char		**map;
	t_player	player;
	t_ray		ray;
	int			**texture_pixels;
	int			**textures;
	t_texinfo	texinfo;
	t_img		minimap;
}	t_game;

// init/data.c
void	init_data(t_game *data);
void	init_img_clean(t_img *img);
void	init_ray(t_ray *ray);

// init/mlx.c
void	init_mlx(t_game *data);
void	init_img(t_game *data, t_img *image, int width, int height);
void	init_texture_img(t_game *data, t_img *image, char *path);

// init/player.c
void	init_player_direction(t_game *data);

// init/textures.c
void	init_textures(t_game *data);
void	init_texinfo(t_texinfo *textures);

// rendering.c
int		render(t_game *data);
void	render_images(t_game *data);

// raycasting.c
int		raycasting(t_player *player, t_game *data);

// texturing.c
void	init_texture_pixels(t_game *data);
void	update_texture_pixels(t_game *data, t_texinfo *tex, t_ray *ray, int x);
void	set_image_pixel(t_img *image, int x, int y, int color);

// render_map.c
void	render_minimap(t_game *data);

// render_image.c
void	render_minimap_image(t_game *data, t_minimap *minimap);

// handle_input.c
void	listen_for_input(t_game *data);

// check_move.c
int		validate_move(t_game *data, double new_x, double new_y);

// move_player.c
int		move_player(t_game *data);

// rotate.c
int		rotate_player(t_game *data, double rotdir);

// quit.c
void	clean_exit(t_game *data, int code);
int		quit_cub3d(t_game *data);

// free.c
void	free_tab(void **tab);
int		free_data(t_game *data);

// error.c
int		err_msg(char *detail, char *str, int code);
int		err_msg_val(int detail, char *str, int code);

// gnl/get_next_line.c
char	*get_next_line(int fd);

// TODO: just for testing, remove later
/* parsing/check_args.c */
int		check_file(char *arg, int cub);

/* parsing/parse_data.c */
void	parse_data(char *path, t_game *data);

/* parsing/get_file_data.c */
int		get_file_data(t_game *data, char **map);

/* parsing/fill_color_textures.c */
int		fill_color_textures(t_game *data, t_texinfo *textures,
			char *line, int j);

/* parsing/create_game_map.c */
int		create_map(t_game *data, char **map, int i);

/* parsing/check_textures.c */
int		check_textures_validity(t_game *data, t_texinfo *textures);

/* parsing/check_map.c */
int		check_map_validity(t_game *data, char **map_tab);

/* parsing/check_map_borders.c */
int		check_map_sides(t_mapinfo *map, char **map_tab);

/* parsing/parsing_utils.c */
int		is_a_white_space(char c);
size_t	find_biggest_len(t_mapinfo *map, int i);


#endif
