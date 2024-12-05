/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaresov <lmaresov@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:11:48 by lmaresov          #+#    #+#             */
/*   Updated: 2024/12/05 10:36:48 by lmaresov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	get_stats(t_game *game, int fd)
{
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			return (1);
		if (empty_line(line))
			continue ;
		get_stats_paths(line, game, fd);
		if (game->mapinfo.map_info == 6)
			break ;
		free(line);
	}
	if (line)
		free(line);
	return (0);
}

char	*map_field_game_helper(t_game *game, char *line)
{
	int		j;
	char	*map_line;

	map_line = malloc(sizeof(char) * (game->mapinfo.width + 2));
	ft_strlcpy(map_line, line, ft_strlen(line) + 1);
	j = ft_strlen(line);
	if (map_line[j - 1] == '\n')
		j--;
	while (j < game->mapinfo.width)
	{
		map_line[j] = ' ';
		j++;
	}
	map_line[j] = '\0';
	return (map_line);
}

void	error_emptyline_free(char **map, char *line, int fd, t_game *game)
{
	read_fd_to_end(fd, line);
	if (map)
		free_tab((void **)map);
	close(fd);
	close_exit(game, "Error\nEmpty line in map\n");
}

void	map_field_to_game(t_game *game, int fd, char **map)
{
	char	*line;
	int		i;
	char	*map_line;

	i = 0;
	game->mapinfo.map_started = 0;
	while (1)
	{
		map[i] = NULL;
		line = get_next_line(fd);
		if (!line)
			break ;
		check_map_char_2(line, game);
		if (is_empty_line(line) && game->mapinfo.map_started \
			&& i < game->mapinfo.height)
			error_emptyline_free(map, line, fd, game);
		if (empty_line(line))
			continue ;
		map_line = map_field_game_helper(game, line);
		map[i] = map_line;
		i++;
		free(line);
	}
	map[i] = NULL;
	game->map = map;
}

int	map_to_game(t_game *game, char *arg)
{
	char	**map;
	int		fd;

	fd = open(arg, O_RDONLY);
	if (fd < 0)
	{
		printf("Error\nCould not open map\n");
		free_texinfo(&game->texinfo);
		return (1);
	}
	if (get_stats(game, fd))
		return (1);
	if (check_colors(game, fd))
		return (1);
	map = malloc(sizeof(char *) * (game->mapinfo.height + 1));
	map_field_to_game(game, fd, map);
	close(fd);
	return (0);
}
