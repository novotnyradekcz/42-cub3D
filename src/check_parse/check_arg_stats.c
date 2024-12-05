/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg_stats.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaresov <lmaresov@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 13:15:35 by lmaresov          #+#    #+#             */
/*   Updated: 2024/12/05 11:00:26 by lmaresov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_map_char_2(char *line, t_game *game)
{
	int	i;

	i = 0;
	while (line[i] && line[i] == ' ')
		i++;
	if (line[i] && ft_strchr("10", line[i]))
	{
		game->mapinfo.map_started = 1;
	}
}

int	check_map_char(char *line, t_game *game)
{
	int	i;

	i = 0;
	while (line[i] && line[i] == ' ')
		i++;
	if (line[i] && ft_strchr("10", line[i]))
	{
		game->mapinfo.map_started = 1;
		game->mapinfo.height++;
		return (1);
	}
	return (0);
}

int	check_stats(char *line, t_game *game)
{
	int	i;

	i = 0;
	while (line[i] && line[i] == ' ')
		i++;
	if (ft_strncmp(&line[i], "NO ", 3) == 0)
		game->check.no++;
	else if (ft_strncmp(&line[i], "SO ", 3) == 0)
		game->check.so++;
	else if (ft_strncmp(&line[i], "WE ", 3) == 0)
		game->check.we++;
	else if (ft_strncmp(&line[i], "EA ", 3) == 0)
		game->check.ea++;
	else if (ft_strncmp(&line[i], "F ", 2) == 0)
		game->check.f++;
	else if (ft_strncmp(&line[i], "C ", 2) == 0)
		game->check.c++;
	else
		return (1);
	return (0);
}

int	check_mapinfo(t_game *game)
{
	if (!(game->check.no == 1 && game->check.so == 1 \
		&& game->check.ea == 1 && game->check.we == 1 \
		&& game->check.c == 1 && game->check.f == 1))
	{
		write (2, "Error\nToo many or missing textures info\n", 41);
		return (1);
	}
	return (0);
}
