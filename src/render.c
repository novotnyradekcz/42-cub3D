/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 08:35:56 by rnovotny          #+#    #+#             */
/*   Updated: 2024/11/28 20:50:30 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_frame_image_pixel(t_game *game, t_img *image, int x, int y)
{
	if (game->texture_pixels[y][x] > 0)
		set_image_pixel(image, x, y, game->texture_pixels[y][x]);
	else if (y < game->win_height / 2)
		set_image_pixel(image, x, y, game->texinfo.hex_ceiling);
	else if (y < game->win_height -1)
		set_image_pixel(image, x, y, game->texinfo.hex_floor);
}

static void	render_frame(t_game *game)
{
	t_img	image;
	int		x;
	int		y;

	image.img = NULL;
	init_img(game, &image, game->win_width, game->win_height);
	y = 0;
	while (y < game->win_height)
	{
		x = 0;
		while (x < game->win_width)
		{
			set_frame_image_pixel(game, &image, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(game->mlx, game->win, image.img, 0, 0);
	render_minimap(game);	// render minimap on top of the frame to get rid of flickering
	mlx_destroy_image(game->mlx, image.img);
}

// static void	render_raycast(t_game *game)
// {
// 	init_texture_pixels(game);
// 	init_ray(&game->ray);
// 	raycasting(&game->player, game);
// 	render_frame(game);
// }

void	render_images(t_game *game)
{
	// render_raycast(game);
	init_texture_pixels(game);
	init_ray(&game->ray);
	raycasting(&game->player, game);
	render_frame(game);

	// render_minimap(game);
}

int	render(t_game *game)
{
	game->player.has_moved += move_player(game);
	if (game->player.has_moved == 0)
		return (0);
	render_images(game);
	return (0);
}
