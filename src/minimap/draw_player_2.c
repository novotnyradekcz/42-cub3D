/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 12:04:13 by rnovotny          #+#    #+#             */
/*   Updated: 2024/12/01 12:05:18 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_player_NE(t_minimap *minimap, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < minimap->tile_size)
	{
		j = 0;
		while (j < i)
		{
			set_image_pixel(minimap->img, x + j, i + y, MMAP_COLOR_FLOOR);
			j++;
		}
		while (j < minimap->tile_size)
		{
			set_image_pixel(minimap->img, x + j, i + y, MMAP_COLOR_PLAYER);
			j++;
		}
		i++;
	}
}

void	draw_player_NW(t_minimap *minimap, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < minimap->tile_size)
	{
		j = 0;
		while (j < minimap->tile_size - i)
		{
			set_image_pixel(minimap->img, x + j, i + y, MMAP_COLOR_PLAYER);
			j++;
		}
		while (j < minimap->tile_size)
		{
			set_image_pixel(minimap->img, x + j, i + y, MMAP_COLOR_FLOOR);
			j++;
		}
		i++;
	}
}

void	draw_player_SW(t_minimap *minimap, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < minimap->tile_size)
	{
		j = 0;
		while (j < i)
		{
			set_image_pixel(minimap->img, x + j, i + y, MMAP_COLOR_PLAYER);
			j++;
		}
		while (j < minimap->tile_size)
		{
			set_image_pixel(minimap->img, x + j, i + y, MMAP_COLOR_FLOOR);
			j++;
		}
		i++;
	}
}

void	draw_player_SE(t_minimap *minimap, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < minimap->tile_size)
	{
		j = 0;
		while (j < minimap->tile_size - i)
		{
			set_image_pixel(minimap->img, x + j, i + y, MMAP_COLOR_FLOOR);
			j++;
		}
		while (j < minimap->tile_size)
		{
			set_image_pixel(minimap->img, x + j, i + y, MMAP_COLOR_PLAYER);
			j++;
		}
		i++;
	}
}
