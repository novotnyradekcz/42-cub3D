/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 08:26:40 by rnovotny          #+#    #+#             */
/*   Updated: 2024/11/09 15:32:28 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_collision(t_game *game, double x, double y)
{
	if (game->player.pos_x < x)
		x += COLLISION_DIST;
	if (game->player.pos_x > x)
		x -= COLLISION_DIST;
	if (game->player.pos_y < y)
		y += COLLISION_DIST;
	if (game->player.pos_y > y)
		y -= COLLISION_DIST;
	if (game->map[(int)y][(int)x] == '0')
		return (1);
	return (0);
}

int	check_move(t_game *game, double new_x, double new_y)
{
	int	moved;

	moved = 0;
	if (check_collision(game, new_x, game->player.pos_y))
	{
		game->player.pos_x = new_x;
		moved = 1;
	}
	if (check_collision(game, game->player.pos_x, new_y))
	{
		game->player.pos_y = new_y;
		moved = 1;
	}
	return (moved);
}
