/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 11:11:29 by rnovotny          #+#    #+#             */
/*   Updated: 2024/11/02 11:25:29 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void	init_game(t_game *game)
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

int	main(int argc, char **argv)
{
	if (argv[1] && argc == 2)
	{
		t_game	game;

		if (check_arg(argv[1]) == 0)
			return (1);
		game.mapinfo.fd = open(argv[1], O_RDONLY);
		if (game.mapinfo.fd < 0)
		{
			write("2, Invalid map\n", 15);
			return (1);
		}
		parse_map(&game);
		// render(&game);
		// listen_for_input(&game);
		// clean_exit(&game, 0);
	}
	else
	{
		write(2, "Usage: ./cub3d map_file\n", 24);
	}
	return (0);
}