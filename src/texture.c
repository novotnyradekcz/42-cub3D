/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaresov <lmaresov@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 08:37:21 by rnovotny          #+#    #+#             */
/*   Updated: 2024/11/23 13:03:19 by lmaresov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_image_pixel(t_img *image, int x, int y, int color)
{
	int	pixel;

	pixel = y * (image->size_line / 4) + x;
	image->addr[pixel] = color;
}

void	init_texture_pixels(t_game *game)
{
	int	i;

	if (game->texture_pixels)
		free_tab((void **)game->texture_pixels);
	game->texture_pixels = ft_calloc(game->win_height + 1,
			sizeof * game->texture_pixels);
	if (!game->texture_pixels)
		clean_exit(game, err_msg(NULL, "malloc error", 1));
	i = 0;
	while (i < game->win_height)
	{
		game->texture_pixels[i] = ft_calloc(game->win_width + 1,
				sizeof * game->texture_pixels);
		if (!game->texture_pixels[i])
			clean_exit(game, err_msg(NULL, "malloc error", 1));
		i++;
	}
}

static void	get_texture_index(t_game *game, t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->dir_x < 0)
			game->texinfo.index = WEST;
		else
			game->texinfo.index = EAST;
	}
	else
	{
		if (ray->dir_y > 0)
			game->texinfo.index = SOUTH;
		else
			game->texinfo.index = NORTH;
	}
}

void	update_texture_pixels(t_game *game, t_texinfo *tex, t_ray *ray, int x)
{
	int			y;
	int			color;
	// (void)x;

	get_texture_index(game, ray);
	tex->x = (int)(ray->wall_x * tex->size);
	if ((ray->side == 0 && ray->dir_x < 0)
		|| (ray->side == 1 && ray->dir_y > 0))
		tex->x = tex->size - tex->x - 1;
	tex->step = 1.0 * tex->size / ray->line_height;
	tex->pos = (ray->draw_start - game->win_height / 2
			+ ray->line_height / 2) * tex->step;
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		tex->y = (int)tex->pos & (tex->size - 1);
		tex->pos += tex->step;
		color = game->textures[tex->index][tex->size * tex->y + tex->x];
		// if (tex->index == NORTH || tex->index == EAST)
		// 	color = (color >> 1) & 8355711;
		if (color > 0)
			game->texture_pixels[y][x] = color;
		y++;
	}
}
