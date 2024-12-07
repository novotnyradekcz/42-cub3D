/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaresov <lmaresov@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:14:19 by lmaresov          #+#    #+#             */
/*   Updated: 2024/12/07 11:30:16 by lmaresov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_color_count(char **sc)
{
	if (!(sc && sc[0] && sc[1] && sc[2]))
	{
		printf("Error\nMissing color\n");
		free_tab((void **)sc);
		return (1);
	}
	if ((sc && sc[3]))
	{
		printf("Error\nToo many color values\n");
		free_tab((void **)sc);
		return (1);
	}
	return (0);
}

int	split_colors(char *color)
{
	char	**splited_color;
	int		i;
	int		col;

	i = 0;
	splited_color = ft_split(color, ',');
	if (check_color_count(splited_color))
	{
		return (1);
	}
	while (i < 3)
	{
		col = ft_atoi(splited_color[i]);
		if (col < 0 || col > 255)
		{
			printf("Error\nColor out of range\n");
			free_tab((void **)splited_color);
			return (1);
		}
		i++;
	}
	free_tab((void **)splited_color);
	return (0);
}

int	check_colors(t_game *game, int fd)
{
	char	*line;

	line = NULL;
	if (split_colors(game->mapinfo.f_c))
	{
		line = get_next_line(fd);
		read_fd_to_end(fd, line);
		free_tex(game);
		return (1);
	}
	else if (split_colors(game->mapinfo.c_c))
	{
		line = get_next_line(fd);
		read_fd_to_end(fd, line);
		free_tex(game);
		return (1);
	}
	return (0);
}

void	free_print_mess(t_game *game, char *message)
{
	printf("%s", message);
	free_texinfo(&game->texinfo);
}
