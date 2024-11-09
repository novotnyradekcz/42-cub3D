/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 08:39:42 by rnovotny          #+#    #+#             */
/*   Updated: 2024/11/09 10:01:34 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	err_msg(char *detail, char *str, int code)
{
	write(2, "cub3D: Error", 12);
	if (detail)
	{
		write(2, ": ", 2);
		write(2, detail, ft_strlen(detail));
	}
	if (str)
	{
		write(2, ": ", 2);
		write(2, str, ft_strlen(str));
	}
	write(2, "\n", 1);
	return (code);
}

int	err_msg_val(int detail, char *str, int code)
{
	char	*tmp;
	
	write(2, "cub3D: Error", 12);
	tmp = ft_itoa(detail);
	write(2, tmp, ft_strlen(tmp));
	free(tmp);
	write(2, ": ", 2);
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	return (code);
}
