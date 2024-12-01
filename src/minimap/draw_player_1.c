/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 11:57:02 by rnovotny          #+#    #+#             */
/*   Updated: 2024/12/01 12:03:16 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_player_E(t_minimap *minimap, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < minimap->tile_size / 2)
	{
		j = 0;
		while (j < 2 * i)
			set_image_pixel(minimap->img, x + j++, i + y, MMAP_COLOR_PLAYER);
		while (j < minimap->tile_size)
			set_image_pixel(minimap->img, x + j++, i + y, MMAP_COLOR_FLOOR);
		i++;
	}
	while (i < minimap->tile_size)
	{
		j = 0;
		while (j < 2 * minimap->tile_size - 2 * i)
			set_image_pixel(minimap->img, x + j++, i + y, MMAP_COLOR_PLAYER);
		while (j < minimap->tile_size)
			set_image_pixel(minimap->img, x + j++, i + y, MMAP_COLOR_FLOOR);
		i++;
	}
}

void	draw_player_N(t_minimap *minimap, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < minimap->tile_size)
	{
		j = 0;
		while (j < (minimap->tile_size - i) / 2)
			set_image_pixel(minimap->img, x + j++, i + y, MMAP_COLOR_FLOOR);
		while (j < (minimap->tile_size + i) / 2)
			set_image_pixel(minimap->img, x + j++, i + y, MMAP_COLOR_PLAYER);
		while (j < minimap->tile_size)
			set_image_pixel(minimap->img, x + j++, i + y, MMAP_COLOR_FLOOR);
		i++;
	}
}

void	draw_player_W(t_minimap *minimap, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < minimap->tile_size / 2)
	{
		j = 0;
		while (j < minimap->tile_size - 2 * i)
			set_image_pixel(minimap->img, x + j++, i + y, MMAP_COLOR_FLOOR);
		while (j < minimap->tile_size)
			set_image_pixel(minimap->img, x + j++, i + y, MMAP_COLOR_PLAYER);
		i++;
	}
	while (i < minimap->tile_size)
	{
		j = 0;
		while (j < 2 * i - minimap->tile_size)
			set_image_pixel(minimap->img, x + j++, i + y, MMAP_COLOR_FLOOR);
		while (j < minimap->tile_size)
			set_image_pixel(minimap->img, x + j++, i + y, MMAP_COLOR_PLAYER);
		i++;
	}
}

void	draw_player_S(t_minimap *minimap, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < minimap->tile_size)
	{
		j = 0;
		while (j < i / 2)
			set_image_pixel(minimap->img, x + j++, i + y, MMAP_COLOR_FLOOR);
		while (j < minimap->tile_size - i / 2)
			set_image_pixel(minimap->img, x + j++, i + y, MMAP_COLOR_PLAYER);
		while (j < minimap->tile_size)
			set_image_pixel(minimap->img, x + j++, i + y, MMAP_COLOR_FLOOR);
		i++;
	}
}
