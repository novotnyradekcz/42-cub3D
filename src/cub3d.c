/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaresov <lmaresov@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 11:11:29 by rnovotny          #+#    #+#             */
/*   Updated: 2024/11/16 13:02:55 by lmaresov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	print_controls(void)
{
	printf("\nWelcome to cub3D the game\n\n");
	printf("\tmove forward:\tW\n");
	printf("\tmove backwards:\tS\n");
	printf("\tmove left:\tA\n");
	printf("\tmove right:\tD\n");
	printf("\trotate left:\tleft arrow\n");
	printf("\trotate right:\tright arrow\n\n");
}
/*
int	check_extension(char *argv)
{
	int	i;
	int	j;

	i = ft_strlen(argv);
	i -= 4;
	if (i < 0)
		return (1);
	if (argv[i] == '.' && argv[i + 1] == 'c' && argv[i + 2] == 'u' && argv[i + 3] == 'b')
		return (0);
	return (1);
}

int	check_file(int fd)
{
	int	result;
	char	buff[1];

	result = read(fd, buff, 1);
	if (result == 0)
	{
		ft_printf("Error\nEmpty file\n");
		close(fd);
		return (1);
	}
	if (result < 0)
	{
		ft_printf("Error\nCould not read map file\n");
		close(fd);
		return (1);
	}
	close(fd);
	return (0);
}

int	check_arg(char *argv)
{
	int		fd;
	int		result;
	char	test[1];

	if (check_extension(argv))
	{
		ft_printf("Error\nWrong extension\n");
		return (1);
	}
	fd = open(argv, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\nCould not open map\n");
		return (1);
	}
	if (check_file(fd))
		return (1);
	return (0);
}

void	init_game(t_game  *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->win_width, game->win_height, "cub3D");
	// game->player.dir = NORTH;
	// game->player.pos_x = 0;
	// game->player.pos_y = 0;
	// game->player.dir_x = 0;
	// game->player.dir_y = 0;
	// game->player.plane_x = 0;
	// game->player.plane_y = 0;
	// game->player.has_moved = 0;
	// game->player.move_x = 0;
	// game->player.move_y = 0;
	// game->player.rotate = 0;
}
*/
// static int	parse_args(t_game *data, char **av)
// {
// 	if (check_file(av[1], 1) == FAILURE)
// 		clean_exit(data, FAILURE);
// 	// parse_data(av[1], data);
// 	// if (get_file_data(data, data->mapinfo.file) == FAILURE)
// 	// 	return (free_data(data));
// 	// if (check_map_validity(data, data->map) == FAILURE)
// 	// 	return (free_data(data));
// 	// if (check_textures_validity(data, &data->texinfo) == FAILURE)
// 	// 	return (free_data(data));
// 	data->mapinfo.width = 10;
// 	data->mapinfo.height = 5;
// 	data->map = malloc(sizeof(char *) * (data->mapinfo.height + 1));
// 	data->map[0] = strdup("1111111111");
// 	data->map[1] = strdup("1000000001");
// 	data->map[2] = strdup("1001111001");
// 	data->map[3] = strdup("1000000001");
// 	data->map[4] = strdup("1111111111");
// 	data->map[5] = NULL;
// 	// data->texinfo.ceiling = malloc(sizeof(int) * 3);
// 	// data->texinfo.floor = malloc(sizeof(int) * 3);
// 	// data->texinfo.ceiling[0] = 100;
// 	// data->texinfo.floor[0] = 200;
// 	// data->texinfo.ceiling[1] = 0;
// 	// data->texinfo.floor[1] = 0;
// 	// data->texinfo.ceiling[2] = 200;
// 	// data->texinfo.floor[2] = 100;
// 	data->texinfo.hex_ceiling = 0xBADBED;
// 	data->texinfo.hex_floor = 0xFFA490;
// 	data->player.pos_x = 4;
// 	data->player.pos_y = 3.5;
// 	data->player.dir = 'N';
	
// 	init_player_direction(data);
// 	// if (DEBUG_MSG)
// 	// 	debug_display_data(data);
// 	return (0);
// }

int	main(int argc, char **argv)
{
	if (argv[1] && argc == 2)
	{
		t_game	game;

		// if (check_arg(argv[1]) == 0)
		// 	return (1);
		// game.mapinfo.fd = open(argv[1], O_RDONLY);
		// if (game.mapinfo.fd < 0)
		// {
		// 	write("2, Invalid map\n", 15);
		// 	return (1);
		// }
		// parse_map(&game);
		init_game(&game);
		if (check_arg(argv[1], &game))
			return (1);
		if (map_to_game(&game, argv[1]))
			return (1);
		check_walls(&game);
		game_before_beginning(&game);
		
		// init_game(&data);
		// if (parse_args(&data, argv) != 0)
		// 	return (1);

		
		init_mlx(&game);
		init_textures(&game);
		print_controls();
		render_images(&game);
		listen_for_input(&game);
		mlx_loop_hook(game.mlx, render, &game);
		mlx_loop(game.mlx);
	}
	else
	{
		write(2, "Usage: ./cub3d map_file\n", 24);
	}
	return (0);
}