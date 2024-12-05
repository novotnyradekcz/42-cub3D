/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaresov <lmaresov@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 12:08:04 by rnovotny          #+#    #+#             */
/*   Updated: 2024/12/05 10:53:46 by lmaresov         ###   ########.fr       */
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

# define WIN_WIDTH 1280
# define WIN_HEIGHT 960

# define TEX_SIZE 1024

# define COLLISION_DIST 0.04

# define MOVE_SPEED 0.025
# define ROT_SPEED 0.025

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
	EAST = 0,
	NORTH = 1,
	WEST = 2,
	SOUTH = 3
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
	char			**tex;
	unsigned long	hex_floor;
	unsigned long	hex_ceiling;
	int				size;
	int				index;
	double			step;
	double			pos;
	int				x;
	int				y;
}	t_texinfo;

typedef struct s_mapinfo
{
	int			fd;
	char		*texture_path[4];
	char		*f_c;
	char		*c_c;
	char		*path;
	char		**file;
	int			height;
	int			width;
	int			index_end_of_map;
	int			map_started;
	int			map_info;
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

typedef struct s_check
{
	int	no;
	int	so;
	int	ea;
	int	we;
	int	c;
	int	f;
	int	n;
	int	s;
	int	e;
	int	w;
}	t_check;

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
	t_check		check;
}	t_game;

// gnl/get_next_line.c
char	*get_next_line(int fd);

// init/game.c
void	init_game(t_game *game);
void	init_img_clean(t_img *img);
void	init_ray(t_ray *ray);

// init/mlx.c
void	init_mlx(t_game *game);
void	init_img(t_game *game, t_img *image, int width, int height);
void	init_texture_img(t_game *game, t_img *image, char *path);

// init/player.c
void	init_player_direction(t_game *game);

// init/textures.c
void	init_textures(t_game *game);
void	init_texinfo(t_texinfo *texinfo);

// rendering.c
int		render(t_game *data);
void	render_raycast(t_game *game);

// raycasting.c
int		raycasting(t_player *player, t_game *data);

// texturing.c
void	init_texture_pixels(t_game *data);
void	update_texture_pixels(t_game *data, t_texinfo *tex, t_ray *ray, int x);
void	set_image_pixel(t_img *image, int x, int y, int color);

// check_move.c
int		check_move(t_game *game, double new_x, double new_y);

// error.c
int		err_msg(char *detail, char *str, int code);
// int		err_msg_val(int detail, char *str, int code);

// free.c
// void	free_texinfo_tex(t_game *game);
void	free_texinfo(t_texinfo *texinfo);
void	free_tab(void **tab);
int		free_game(t_game *game);

// handle_input.c
void	listen_for_input(t_game *game);

// move_player.c
int		move_player(t_game *game);

// quit.c
void	clean_exit(t_game *game, int code);
int		quit_cub3d(t_game *game);

// render.c
int		render(t_game *game);
void	render_images(t_game *game);

// raycast.c
int		raycasting(t_player *player, t_game *game);

// rotate.c
int		rotate_player(t_game *game, double rotdir);

// texture.c
void	update_texture_pixels(t_game *game, t_texinfo *tex, t_ray *ray, int x);
void	init_texture_pixels(t_game *game);

//check_arg_mapinfo.c
void	count_map_char(t_game *game, char letter);
int		mapinfo_checker(char *line, t_game *game);
int		check_map(t_game *game);
int		is_empty_line(char *line);
int		empty_line(char *line);

//check_arg_stats.c
int		check_map_char(char *line, t_game *game);
void	check_map_char_2(char *line, t_game *game);
int		check_stats(char *line, t_game *game);
int		check_mapinfo(t_game *game);

//check_arg.c
void	init_check_game(t_game *game);
int		check_extension(char *argv);
int		check_map_file_helper(int fd, char *line, t_game *game);
int		check_map_file(int fd, t_game *game);
int		check_arg(char *argv, t_game *game);

//check_color.c
int		check_colors(t_game *game, int fd);
void	free_print_mess(t_game *game, char *message);
//check_walls.c
void	check_walls(t_game *game);

//ending_game.c
void	free_all(t_game *game);
void	free_a(t_game *game);
void	close_exit(t_game *game, char *message);

//game_before_beginning.c
void	game_before_beginning(t_game *game);

//get_stats.c
// void	get_stats_paths(char *line, t_game *game);
void	get_stats_paths(char *line, t_game *game, int fd);
void	free_tex(t_game *game);

//map_info_utils.c
void	map_width(char *line, t_game *game);
void	read_fd_to_end(int fd, char *line);

//map_to_game.c
int		map_to_game(t_game *game, char *arg);
#endif
