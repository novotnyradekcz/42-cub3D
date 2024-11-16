/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 08:27:40 by rnovotny          #+#    #+#             */
/*   Updated: 2024/11/16 10:49:05 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// TODO: possibly refactor into one function

static int	rotate_left_right(t_game *game, double rotspeed)
{
	t_player	*p;
	double		tmp_x;

	p = &game->player;
	tmp_x = p->dir_x;
	p->dir_x = p->dir_x * cos(rotspeed) - p->dir_y * sin(rotspeed);
	p->dir_y = tmp_x * sin(rotspeed) + p->dir_y * cos(rotspeed);
	tmp_x = p->plane_x;
	p->plane_x = p->plane_x * cos(rotspeed) - p->plane_y * sin(rotspeed);
	p->plane_y = tmp_x * sin(rotspeed) + p->plane_y * cos(rotspeed);
	return (1);
}

int	rotate_player(t_game *game, double rotdir)
{
	int		moved;
	double	rotspeed;

	moved = 0;
	rotspeed = ROT_SPEED * rotdir;
	moved += rotate_left_right(game, rotspeed);
	return (moved);
}
