/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaresov <lmaresov@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 08:39:42 by rnovotny          #+#    #+#             */
/*   Updated: 2024/11/25 11:26:28 by lmaresov         ###   ########.fr       */
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
