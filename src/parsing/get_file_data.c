/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 22:29:52 by alexa             #+#    #+#             */
/*   Updated: 2024/11/16 08:52:49 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static char	*get_texture_path(char *line, int j)
{
	int		len;
	int		i;
	char	*path;

	while (line[j] && (line[j] == ' ' || line[j] == '\t'))
		j++;
	len = j;
	while (line[len] && (line[len] != ' ' && line[len] != '\t'))
		len++;
	path = malloc(sizeof(char) * (len - j + 1));
	if (!path)
		return (NULL);
	i = 0;
	while (line[j] && (line[j] != ' ' && line[j] != '\t' && line[j] != '\n'))
		path[i++] = line[j++];
	path[i] = '\0';
	while (line[j] && (line[j] == ' ' || line[j] == '\t'))
		j++;
	if (line[j] && line[j] != '\n')
	{
		free(path);
		path = NULL;
	}
	return (path);
}

static int	fill_direction_textures(t_texinfo *textures, char *line, int j)
{
	if (line[j + 2] && ft_isprint(line[j + 2]))
		return (ERR);
	if (line[j] == 'N' && line[j + 1] == 'O' && !(textures->tex[NORTH]))
		textures->tex[NORTH] = get_texture_path(line, j + 2);
	else if (line[j] == 'S' && line[j + 1] == 'O' && !(textures->tex[SOUTH]))
		textures->tex[SOUTH] = get_texture_path(line, j + 2);
	else if (line[j] == 'W' && line[j + 1] == 'E' && !(textures->tex[WEST]))
		textures->tex[WEST] = get_texture_path(line, j + 2);
	else if (line[j] == 'E' && line[j + 1] == 'A' && !(textures->tex[EAST]))
		textures->tex[EAST] = get_texture_path(line, j + 2);
	else
		return (ERR);
	return (SUCCESS);
}

static int	ignore_whitespaces_get_info(t_game *data, char **map, int i, int j)
{
	while (map[i][j] == ' ' || map[i][j] == '\t' || map[i][j] == '\n')
		j++;
	if (ft_isprint(map[i][j]) && !ft_isdigit(map[i][j]))
	{
		if (map[i][j + 1] && ft_isprint(map[i][j + 1])
			&& !ft_isdigit(map[i][j]))
		{
			if (fill_direction_textures(&data->texinfo, map[i], j) == ERR)
				return (err_msg(data->mapinfo.path, "missing texture", FAILURE));
			return (BREAK);
		}	
		else
		{
			if (fill_color_textures(data, &data->texinfo, map[i], j) == ERR)
				return (FAILURE);
			return (BREAK);
		}	
	}
	else if (ft_isdigit(map[i][j]))
	{
		if (create_map(data, map, i) == FAILURE)
			return (err_msg(data->mapinfo.path, "invalid map", FAILURE));
		return (SUCCESS);
	}
	return (CONTINUE);
}

int	get_file_data(t_game *data, char **map)
{
	int	i;
	int	j;
	int	ret;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			ret = ignore_whitespaces_get_info(data, map, i, j);
			if (ret == BREAK)
				break ;
			else if (ret == FAILURE)
				return (FAILURE);
			else if (ret == SUCCESS)
				return (SUCCESS);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}
