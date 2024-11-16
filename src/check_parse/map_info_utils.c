/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_info_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaresov <lmaresov@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 13:13:08 by lmaresov          #+#    #+#             */
/*   Updated: 2024/11/16 12:03:18 by lmaresov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	map_width(char *line, t_game *game)
{
	int	i;

	i = 0;
	while (line [i] && line[i] != '\n')
	{
		i++;
	}
	if (game->mapinfo.width < i)
		game->mapinfo.width = i;
}
