/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaresov <lmaresov@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 08:18:03 by rnovotny          #+#    #+#             */
/*   Updated: 2024/12/05 08:06:49 by lmaresov         ###   ########.fr       */
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
	game->textures[NORTH] = xpm_to_img(game, game->mapinfo.texture_path[NORTH]);
	game->textures[SOUTH] = xpm_to_img(game, game->mapinfo.texture_path[SOUTH]);
	game->textures[EAST] = xpm_to_img(game, game->mapinfo.texture_path[EAST]);
	game->textures[WEST] = xpm_to_img(game, game->mapinfo.texture_path[WEST]);
}

void	init_texinfo(t_texinfo *texinfo)
{
	texinfo->tex[NORTH] = NULL;
	texinfo->tex[SOUTH] = NULL;
	texinfo->tex[WEST] = NULL;
	texinfo->tex[EAST] = NULL;
	texinfo->hex_floor = 0x0;
	texinfo->hex_ceiling = 0x0;
	texinfo->size = TEX_SIZE;
	texinfo->step = 0.0;
	texinfo->pos = 0.0;
	texinfo->x = 0;
	texinfo->y = 0;
}
