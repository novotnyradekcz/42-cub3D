/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 10:10:45 by rnovotny          #+#    #+#             */
/*   Updated: 2024/11/02 10:11:01 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

parse_map(t_game *game)
{
	char	*line;
	int		ret;

	ret = get_next_line(game->mapinfo.fd, &line);
	while (ret > 0)
	{
		printf("%s\n", line);
		free(line);
		ret = get_next_line(game->mapinfo.fd, &line);
	}
	if (ret < 0)
	{
		write(2, "Error reading map\n", 18);
	}
}