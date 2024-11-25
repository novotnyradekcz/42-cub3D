/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaresov <lmaresov@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 09:13:30 by lmaresov          #+#    #+#             */
/*   Updated: 2024/11/25 09:04:30 by lmaresov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_check_game(t_game *game)
{
	game->check.c = 0;
	game->check.ea = 0;
	game->check.f = 0;
	game->check.no = 0;
	game->check.so = 0;
	game->check.we = 0;
	game->check.n = 0;
	game->check.s = 0;
	game->check.e = 0;
	game->check.w = 0;
}

int	check_extension(char *argv)
{
	int	i;

	i = ft_strlen(argv);
	i -= 4;
	if (i < 0)
		return (1);
	if (argv[i] == '.' && argv[i + 1] == 'c'\
		&& argv[i + 2] == 'u' && argv[i + 3] == 'b')
		return (0);
	return (1);
}

int	check_map_file_helper(int fd, char *line, t_game *game)
{
	map_width(line, game);
	if (mapinfo_checker(line, game))
		return (1);
	free(line);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (empty_line(line))
			continue ;
		map_width(line, game);
		if (mapinfo_checker(line, game))
			return (1);
		game->mapinfo.height++;
		free(line);
	}
	if (check_map(game))
		return (1);
	return (0);
}

int	check_map_file(int fd, t_game *game)
{
	char	*line;

	while (!game->mapinfo.map_started)
	{
		line = get_next_line(fd);
		if (!line)
			return (1);
		if (empty_line(line))
			continue ;
		if (check_stats(line, game))
		{
			if (check_map_char(line, game))
				break ;
			return (1);
		}
		free(line);
	}
	if (check_map_file_helper(fd, line, game))
		return (1);
	return (0);
}

int	check_arg(char *argv, t_game *game)
{
	int	fd;

	if (check_extension(argv))
	{
		printf("Error\nWrong extension\n");
		free_texinfo_tex(game);
		return (1);
	}
	fd = open(argv, O_RDONLY);
	if (fd < 0)
	{
		printf("Error\nCould not open map\n");
		free_texinfo_tex(game);
		return (1);
	}
	if (check_map_file(fd, game))
	{
		close(fd);
		free_texinfo_tex(game);
		return (1);
	}
	close(fd);
	game->mapinfo.map_started = 0;
	return (0);
}
