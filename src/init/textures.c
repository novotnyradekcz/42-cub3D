/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 08:18:03 by rnovotny          #+#    #+#             */
/*   Updated: 2024/11/09 13:26:20 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../cub3d.h"

static int	*xpm_to_img(t_game *data, char *path)
{
	t_img	tmp;
	int		*buffer;
	int		x;
	int		y;

	init_texture_img(data, &tmp, path);
	buffer = ft_calloc(1,
			sizeof * buffer * data->texinfo.size * data->texinfo.size);
	if (!buffer)
		clean_exit(data, err_msg(NULL, "malloc error", 1));
	y = 0;
	while (y < data->texinfo.size)
	{
		x = 0;
		while (x < data->texinfo.size)
		{
			buffer[y * data->texinfo.size + x]
				= tmp.addr[y * data->texinfo.size + x];
			++x;
		}
		y++;
	}
	mlx_destroy_image(data->mlx, tmp.img);
	return (buffer);
}

void	init_textures(t_game *data)
{
	data->textures = ft_calloc(5, sizeof * data->textures);
	if (!data->textures)
		clean_exit(data, err_msg(NULL, "malloc error", 1));
	// data->textures[NORTH] = xpm_to_img(data, data->texinfo.north);
	// data->textures[SOUTH] = xpm_to_img(data, data->texinfo.south);
	// data->textures[EAST] = xpm_to_img(data, data->texinfo.east);
	// data->textures[WEST] = xpm_to_img(data, data->texinfo.west);
	data->textures[NORTH] = xpm_to_img(data, "textures/wolfenstein/blue_stone.xpm");
	data->textures[SOUTH] = xpm_to_img(data, "textures/wolfenstein/color_stone.xpm");
	data->textures[EAST] = xpm_to_img(data, "textures/wolfenstein/grey_stone.xpm");
	data->textures[WEST] = xpm_to_img(data, "textures/wolfenstein/purple_stone.xpm");
}

void	init_texinfo(t_texinfo *textures)
{
	textures->north = NULL;
	textures->south = NULL;
	textures->west = NULL;
	textures->east = NULL;
	textures->floor = 0;
	textures->ceiling = 0;
	textures->hex_floor = 0x0;
	textures->hex_ceiling = 0x0;
	textures->size = TEX_SIZE;
	textures->step = 0.0;
	textures->pos = 0.0;
	textures->x = 0;
	textures->y = 0;
}
