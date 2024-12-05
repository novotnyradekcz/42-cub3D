/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stats.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaresov <lmaresov@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 12:02:02 by lmaresov          #+#    #+#             */
/*   Updated: 2024/12/05 11:28:55 by lmaresov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_tex(t_game *game)
{
	if (game->mapinfo.texture_path[NORTH])
		free(game->mapinfo.texture_path[NORTH]);
	if (game->mapinfo.texture_path[SOUTH])
		free(game->mapinfo.texture_path[SOUTH]);
	if (game->mapinfo.texture_path[EAST])
		free(game->mapinfo.texture_path[EAST]);
	if (game->mapinfo.texture_path[WEST])
		free(game->mapinfo.texture_path[WEST]);
	if (game->mapinfo.c_c)
		free(game->mapinfo.c_c);
	if (game->mapinfo.f_c)
		free(game->mapinfo.f_c);
	if (game->texinfo.tex)
		free(game->texinfo.tex);
}

void	free_stats_splited_exit(char **stats, char *line, int fd, t_game *game)
{
	int	i;

	i = 0;
	while (stats[i])
	{
		free(stats[i]);
		i++;
	}
	free(stats);
	read_fd_to_end(fd, line);
	free_tex(game);
	printf("Error:\nSpaces in paths or between colors\n");
	exit (1);
}

void	get_stats_path_helper(t_game *game, char **stats_splited)
{
	if (ft_strncmp("NO", stats_splited[0], 2) == 0)
		game->mapinfo.texture_path[NORTH] = stats_splited[1];
	else if (ft_strncmp("SO", stats_splited[0], 2) == 0)
		game->mapinfo.texture_path[SOUTH] = stats_splited[1];
	else if (ft_strncmp("EA", stats_splited[0], 2) == 0)
		game->mapinfo.texture_path[EAST] = stats_splited[1];
	else if (ft_strncmp("WE", stats_splited[0], 2) == 0)
		game->mapinfo.texture_path[WEST] = stats_splited[1];
	else if (ft_strncmp("C", stats_splited[0], 1) == 0)
		game->mapinfo.c_c = stats_splited[1];
	else if (ft_strncmp("F", stats_splited[0], 1) == 0)
		game->mapinfo.f_c = stats_splited[1];
}

void	get_stats_paths(char *line, t_game *game, int fd)
{
	char	**stats_splited;
	int		i;
	int		path_len;

	i = 0;
	stats_splited = ft_split(line, ' ');
	while (stats_splited[i])
		i++;
	if (--i >= 2 && ft_strncmp(stats_splited[2], "\n", 1) != 0)
		free_stats_splited_exit(stats_splited, line, fd, game);
	if (stats_splited[2] && ft_strncmp(stats_splited[2], "\n", 1) == 0)
		free(stats_splited[2]);
	path_len = ft_strlen(stats_splited[1]);
	if (stats_splited[1][path_len - 1] == '\n')
		stats_splited[1][path_len - 1] = '\0' ;
	get_stats_path_helper(game, stats_splited);
	free (stats_splited[0]);
	free (stats_splited);
	game->mapinfo.map_info++;
}
