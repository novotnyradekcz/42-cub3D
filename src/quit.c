/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 08:10:32 by rnovotny          #+#    #+#             */
/*   Updated: 2024/11/16 10:35:55 by rnovotny         ###   ########.fr       */
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
