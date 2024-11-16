/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 08:33:02 by rnovotny          #+#    #+#             */
/*   Updated: 2024/11/16 10:18:48 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	get_mmap_offset(t_minimap *minimap, int mapsize, int pos)
{
	if (pos > minimap->view_dist && mapsize - pos > minimap->view_dist + 1)
		return (pos - minimap->view_dist);
	if (pos > minimap->view_dist && mapsize - pos <= minimap->view_dist + 1)
		return (mapsize - minimap->size);
	return (0);
}

static int	is_valid_map_coord(int coord, int size)
{
	if (coord < size)
		return (1);
	return (0);
}

static char	*add_minimap_line(t_game *game, t_minimap *map, int y)
{
	char	*line;
	int		x;

	line = ft_calloc(map->size + 1, sizeof * line);
	if (!line)
		return (NULL);
	x = 0;
	while (x < map->size && x < game->mapinfo.width)
	{
		if (!is_valid_map_coord(y + map->offset_y, game->mapinfo.height)
			|| !is_valid_map_coord(x + map->offset_x, game->mapinfo.width))
			line[x] = '\0';
		else if ((int)game->player.pos_x == (x + map->offset_x)
			&& (int)game->player.pos_y == (y + map->offset_y))
			line[x] = 'P';
		else if (game->map[y + map->offset_y][x + map->offset_x] == '1')
			line[x] = '1';
		else if (game->map[y + map->offset_y][x + map->offset_x] == '0')
			line[x] = '0';
		else
			line[x] = '\0';
		x++;
	}
	return (line);
}

static char	**generate_minimap(t_game *game, t_minimap *minimap)
{
	char	**mmap;
	int		y;

	mmap = ft_calloc(minimap->size + 1, sizeof * mmap);
	if (!mmap)
		return (NULL);
	y = 0;
	while (y < minimap->size && y < game->mapinfo.height)
	{
		mmap[y] = add_minimap_line(game, minimap, y);
		if (!mmap[y])
		{
			free_tab((void **)mmap);
			return (NULL);
		}
		y++;
	}
	return (mmap);
}

void	render_minimap(t_game *game)
{
	t_minimap	minimap;

	minimap.map = NULL;
	minimap.img = &game->minimap;
	minimap.view_dist = MMAP_VIEW_DIST;
	minimap.size = (2 * minimap.view_dist) + 1;
	minimap.tile_size = MMAP_PIXEL_SIZE / (2 * minimap.view_dist);
	minimap.offset_x = get_mmap_offset(&minimap,
			game->mapinfo.width, (int)game->player.pos_x);
	minimap.offset_y = get_mmap_offset(&minimap,
			game->mapinfo.height, (int)game->player.pos_y);
	minimap.map = generate_minimap(game, &minimap);
	if (!minimap.map)
	{
		err_msg(NULL, "malloc error", 0);
		return ;
	}
	render_minimap_image(game, &minimap);
	free_tab((void **)minimap.map);
}
