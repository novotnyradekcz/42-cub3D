/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 22:17:27 by alexa             #+#    #+#             */
/*   Updated: 2024/11/09 12:54:13 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*
**	Checks whether the arg given is a correct .cub extension, checks that
**	 it exists and isn't a folder instead of a file.
*/

static int	is_dir(char *arg)
{
	int	fd;
	int	ret;

	ret = 0;
	fd = open(arg, O_DIRECTORY);
	if (fd >= 0)
	{
		close (fd);
		ret = 1;
	}
	return (ret);
}

static int	is_cub_file(char *arg)
{
	size_t	len;

	len = ft_strlen(arg);
	if ((arg[len - 3] != 'c' || arg[len - 2] != 'u'
			|| arg[len - 1] != 'b'
			|| arg[len - 4] != '.'))
		return (0);
	return (1);
}

static int	is_xpm_file(char *arg)
{
	size_t	len;

	len = ft_strlen(arg);
	if ((arg[len - 3] != 'x' || arg[len - 2] != 'p'
			|| arg[len - 1] != 'm'
			|| arg[len - 4] != '.'))
		return (0);
	return (1);
}

int	check_file(char *arg, int cub)
{
	int	fd;

	if (is_dir(arg))
		return (err_msg(arg, "not a file", FAILURE));
	fd = open(arg, O_RDONLY);
	if (fd == -1)
		return (err_msg(arg, strerror(errno), FAILURE));
	close(fd);
	if (cub && !is_cub_file(arg))
		return (err_msg(arg, "not .cub", FAILURE));
	if (!cub && !is_xpm_file(arg))
		return (err_msg(arg, "not .xpm", FAILURE));
	return (SUCCESS);
}
