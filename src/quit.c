/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaresov <lmaresov@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 08:10:32 by rnovotny          #+#    #+#             */
/*   Updated: 2024/11/16 12:54:23 by lmaresov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	clean_exit(t_game *game, int code)
{
	if (!game)
		exit(code);
	if (game->win && game->mlx)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		mlx_loop_end(game->mlx);
		free(game->mlx);
	}
	free_game(game);
	exit(code);
}

int	quit_cub3d(t_game *game)
{
	clean_exit(game, 0);
	return (0);
}


void	free_a(t_game *game)
{
	int	i;

	i = 0;
	if (game->mapinfo.c_c)
		free(game->mapinfo.c_c);
	if (game->mapinfo.f_c)
		free(game->mapinfo.f_c);
	while (i < 4)
	{
		if (game->mapinfo.texture_path[i])
			free(game->mapinfo.texture_path[i]);
		i++;
	}
}

void	free_all(t_game *game)
{
	int	i;

	i = 0;
	if (game->mapinfo.c_c)
		free(game->mapinfo.c_c);
	if (game->mapinfo.f_c)
		free(game->mapinfo.f_c);
	while (i < 4)
	{
		if (game->mapinfo.texture_path[i])
			free(game->mapinfo.texture_path[i]);
		i++;
	}
	i = 0;
	if (game->map)
	{
		while (game->map[i])
		{
			free(game->map[i]);
			i++;
		}
		free(game->map);
	}
}

void	close_exit(t_game *game, char *message)
{
	write(2, message, ft_strlen(message));
	free_all(game);
	exit(1);
}