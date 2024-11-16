/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_before_beginning.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaresov <lmaresov@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 15:08:46 by lmaresov          #+#    #+#             */
/*   Updated: 2024/11/16 13:09:34 by lmaresov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

unsigned int	rgb_to_hex(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

unsigned int	hexa_color(char **rgb)
{
	int				i;
	int				rgb_num[3];
	unsigned int	hexa;

	i = 0;
	rgb_num[0] = ft_atoi(rgb[0]);
	rgb_num[1] = ft_atoi(rgb[1]);
	rgb_num[2] = ft_atoi(rgb[2]);
	hexa = rgb_to_hex(rgb_num[0], rgb_num[1], rgb_num[2]);
	while (rgb[i])
	{
		free(rgb[i]);
		i++;
	}
	free(rgb);
	return (hexa);
}

void	get_color(t_game *game)
{
	game->texinfo.hex_ceiling = hexa_color(ft_split(game->mapinfo.c_c, ','));
	game->texinfo.hex_floor = hexa_color(ft_split(game->mapinfo.f_c, ','));
	// printf ("moje u long c: %u\n", game->mapinfo.hexa_c);
	// printf("moje u long f: %u\n", game->mapinfo.hexa_f);
	// printf ("moje hexa c: %X\n", game->mapinfo.hexa_c);
	// printf("moje hexa f: %X\n", game->mapinfo.hexa_f);
}

void	get_player_dir(t_game *game, int j, int i)
{
	if (ft_strchr("N", game->map[j][i]))
		game->player.dir = 'N';
	else if (ft_strchr("S", game->map[j][i]))
		game->player.dir = 'S';
	else if (ft_strchr("E", game->map[j][i]))
		game->player.dir = 'E';
	else if (ft_strchr("W", game->map[j][i]))
		game->player.dir = 'W';
}

void	game_before_beginning(t_game *game)
{
	int	j;
	int	i;

	j = 0;
	get_color(game);
	while (game->map[j])
	{
		i = 0;
		while (game->map[j] && game->map[j][i])
		{
			get_player_dir(game, j, i);
			if (ft_strchr("NSEW", game->map[j][i]))
			{
				game->player.pos_x = i;
				game->player.pos_y = j;
				game->map[j][i] = '0';
				return ;
			}
			i++;
		}
		j++;
	}
}
