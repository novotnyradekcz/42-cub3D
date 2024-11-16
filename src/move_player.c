/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 08:24:48 by rnovotny          #+#    #+#             */
/*   Updated: 2024/11/16 10:39:54 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	move_forward(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos_x + game->player.dir_x * MOVE_SPEED;
	new_y = game->player.pos_y + game->player.dir_y * MOVE_SPEED;
	return (check_move(game, new_x, new_y));
}

static int	move_backwards(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos_x - game->player.dir_x * MOVE_SPEED;
	new_y = game->player.pos_y - game->player.dir_y * MOVE_SPEED;
	return (check_move(game, new_x, new_y));
}

static int	move_left(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos_x + game->player.dir_y * MOVE_SPEED;
	new_y = game->player.pos_y - game->player.dir_x * MOVE_SPEED;
	return (check_move(game, new_x, new_y));
}

static int	move_right(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos_x - game->player.dir_y * MOVE_SPEED;
	new_y = game->player.pos_y + game->player.dir_x * MOVE_SPEED;
	return (check_move(game, new_x, new_y));
}

int	move_player(t_game *game)
{
	int	moved;

	moved = 0;
	if (game->player.move_y == 1)
		moved += move_forward(game);
	if (game->player.move_y == -1)
		moved += move_backwards(game);
	if (game->player.move_x == -1)
		moved += move_left(game);
	if (game->player.move_x == 1)
		moved += move_right(game);
	if (game->player.rotate != 0)
		moved += rotate_player(game, game->player.rotate);
	return (moved);
}
