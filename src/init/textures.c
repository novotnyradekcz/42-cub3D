/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 08:18:03 by rnovotny          #+#    #+#             */
/*   Updated: 2024/11/16 12:06:23 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	*xpm_to_img(t_game *game, char *path)
{
	t_img	tmp;
	int		*buffer;
	int		x;
	int		y;

	init_texture_img(game, &tmp, path);
	buffer = ft_calloc(1,
			sizeof * buffer * game->texinfo.size * game->texinfo.size);
	if (!buffer)
		clean_exit(game, err_msg(NULL, "malloc error", 1));
	y = 0;
	while (y < game->texinfo.size)
	{
		x = 0;
		while (x < game->texinfo.size)
		{
			buffer[y * game->texinfo.size + x]
				= tmp.addr[y * game->texinfo.size + x];
			++x;
		}
		y++;
	}
	mlx_destroy_image(game->mlx, tmp.img);
	return (buffer);
}

void	init_textures(t_game *game)
{
	game->textures = ft_calloc(5, sizeof * game->textures);
	if (!game->textures)
		clean_exit(game, err_msg(NULL, "malloc error", 1));
	// data->textures[NORTH] = xpm_to_img(data, data->texinfo.north);
	// data->textures[SOUTH] = xpm_to_img(data, data->texinfo.south);
	// data->textures[EAST] = xpm_to_img(data, data->texinfo.east);
	// data->textures[WEST] = xpm_to_img(data, data->texinfo.west);
	game->textures[NORTH] = xpm_to_img(game, "textures/wolfenstein/blue_stone.xpm");
	game->textures[SOUTH] = xpm_to_img(game, "textures/wolfenstein/color_stone.xpm");
	game->textures[EAST] = xpm_to_img(game, "textures/wolfenstein/grey_stone.xpm");
	game->textures[WEST] = xpm_to_img(game, "textures/wolfenstein/purple_stone.xpm");
}

void	init_texinfo(t_texinfo *texinfo)
{
	texinfo->tex[NORTH] = NULL;
	texinfo->tex[SOUTH] = NULL;
	texinfo->tex[WEST] = NULL;
	texinfo->tex[EAST] = NULL;
	texinfo->floor = 0;
	texinfo->ceiling = 0;
	texinfo->hex_floor = 0x0;
	texinfo->hex_ceiling = 0x0;
	texinfo->size = TEX_SIZE;
	texinfo->step = 0.0;
	texinfo->pos = 0.0;
	texinfo->x = 0;
	texinfo->y = 0;
}
