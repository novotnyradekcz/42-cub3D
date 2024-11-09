/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 08:26:40 by rnovotny          #+#    #+#             */
/*   Updated: 2024/11/09 12:30:31 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_valid_pos_wall_collision(t_game *data, double x, double y)
{
	if (data->map[(int)y][(int)x] == '0')
		return (1);
	return (0);
}
/*
static int	is_valid_pos_in_map(t_game *data, double x, double y)
{
	if (x < 0.25 || x >= data->mapinfo.width - 1.25)
		return (0);
	if (y < 0.25 || y >= data->mapinfo.height -0.25)
		return (0);
	return (1);
}
*/
static int	is_valid_pos(t_game *data, double x, double y)
{
	// if (!BONUS && is_valid_pos_in_map(data, x, y))
	// 	return (1);
	if (is_valid_pos_wall_collision(data, x, y))
		return (1);
	return (0);
}

int	validate_move(t_game *data, double new_x, double new_y)
{
	int	moved;

	moved = 0;
	if (is_valid_pos(data, new_x, data->player.pos_y))
	{
		data->player.pos_x = new_x;
		moved = 1;
	}
	if (is_valid_pos(data, data->player.pos_x, new_y))
	{
		data->player.pos_y = new_y;
		moved = 1;
	}
	return (moved);
}
