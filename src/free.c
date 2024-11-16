/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaresov <lmaresov@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 08:11:43 by rnovotny          #+#    #+#             */
/*   Updated: 2024/11/16 12:55:18 by lmaresov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_tab(void **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	if (tab)
	{
		free(tab);
		tab = NULL;
	}
}

static void	free_texinfo(t_texinfo *texinfo)
{
	if (texinfo->tex[NORTH])
		free(texinfo->tex[NORTH]);
	if (texinfo->tex[SOUTH])
		free(texinfo->tex[SOUTH]);
	if (texinfo->tex[WEST])
		free(texinfo->tex[WEST]);
	if (texinfo->tex[EAST])
		free(texinfo->tex[EAST]);
	if (texinfo->tex)
		free(texinfo->tex);
	// if (texinfo->floor)
	// 	free(texinfo->floor);
	// if (texinfo->ceiling)
	// 	free(texinfo->ceiling);
}

static void	free_map(t_game *game)
{
	if (game->mapinfo.fd > 0)
		close(game->mapinfo.fd);
	if (game->mapinfo.file)
		free_tab((void **)game->mapinfo.file);
	if (game->map)
		free_tab((void **)game->map);
}

int	free_game(t_game *game)
{
	free_all(game);
	if (game->textures)
		free_tab((void **)game->textures);
	if (game->texture_pixels)
		free_tab((void **)game->texture_pixels);
	free_texinfo(&game->texinfo);
	free_map(game);
	return (FAILURE);
}
