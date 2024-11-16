/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 08:13:05 by rnovotny          #+#    #+#             */
/*   Updated: 2024/11/16 12:07:15 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_img(t_game *game, t_img *image, int width, int height)
{
	init_img_clean(image);
	image->img = mlx_new_image(game->mlx, width, height);
	if (image->img == NULL)
		clean_exit(game, err_msg("mlx", "mlx image error", 1));
	image->addr = (int *)mlx_get_data_addr(image->img, &image->pixel_bits,
			&image->size_line, &image->endian);
	return ;
}

void	init_texture_img(t_game *game, t_img *image, char *path)
{
	init_img_clean(image);
	image->img = mlx_xpm_file_to_image(game->mlx, path, &game->texinfo.size,
			&game->texinfo.size);
	if (image->img == NULL)
		clean_exit(game, err_msg("mlx", "mlx image error", 1));
	image->addr = (int *)mlx_get_data_addr(image->img, &image->pixel_bits,
			&image->size_line, &image->endian);
	return ;
}

void	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		clean_exit(game, err_msg("mlx", "mlx start error", 1));
	game->win = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	if (!game->win)
		clean_exit(game, err_msg("mlx", "mlx window error", 1));
	return ;
}
