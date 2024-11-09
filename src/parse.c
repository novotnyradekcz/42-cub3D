/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 10:10:45 by rnovotny          #+#    #+#             */
/*   Updated: 2024/11/09 12:39:15 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parse_map(t_game  *game)
{
	char	*line;

	line = get_next_line(game->mapinfo.fd);
	while (ft_strlen(line) > 0)
	{
		printf("%s\n", line);
		free(line);
		line = get_next_line(game->mapinfo.fd);
	}
}