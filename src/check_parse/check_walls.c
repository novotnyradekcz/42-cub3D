/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaresov <lmaresov@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:35:17 by lmaresov          #+#    #+#             */
/*   Updated: 2024/11/25 09:27:32 by lmaresov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_vertical_walls(t_game *game)
{
	int		i;
	int		j;
	char	**map;

	map = game->map;
	j = 0;
	while (map[j] != NULL)
	{
		i = 0;
		while (map[j][i] != '\0')
		{
			while (map[j][i] != '\0' && map[j][i] == ' ')
				i++;
			if (map[j][i] != '\0' && map[j][i] != '1')
				close_exit(game, "Error\nIncomplete vertical wall\n");
			while (map[j][i] != '\0' && ft_strchr("10NESW", map[j][i]))
				i++;
			if (map[j][i] == '\0' && map[j][i - 1] == ' ')
				break ;
			if (map[j][i - 1] != '1')
				close_exit(game, "Error\nIncomplete vertical wall\n");
		}
		j++;
	}
}

void	check_horisontal_walls(t_game *game)
{
	int		i;
	int		j;
	char	**map;

	map = game->map;
	i = 0;
	while (i < game->mapinfo.width)
	{
		j = 0;
		while (j < game->mapinfo.height)
		{
			while (map[j] && map[j][i] && map[j][i] == ' ')
				j++;
			if (map[j] && map[j][i] && map[j][i] != '1')
				close_exit(game, "Error\nIncomplete horizontal wall\n");
			while (map[j] && map[j][i] && ft_strchr("10NESW", map[j][i]))
				j++;
			if (map[j] == NULL && map[j - 1][i] == ' ')
				break ;
			if (map[j - 1] && map[j - 1][i] != '1')
				close_exit(game, "Error\nIncomplete horizontal wall\n");
		}
		i++;
	}
}

void	check_walls(t_game *game)
{
	check_vertical_walls(game);
	check_horisontal_walls(game);
}
