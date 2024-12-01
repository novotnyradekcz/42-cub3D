/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaresov <lmaresov@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 20:28:35 by rnovotny          #+#    #+#             */
/*   Updated: 2024/11/25 10:54:30 by lmaresov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*output_line(char *str)
{
	int		i;
	char	*outputline;

	i = 0;
	outputline = (char *)malloc((ft_strlen_end(str, '\n') + 2) * sizeof(char));
	if (!outputline)
		return (0);
	while (str[i] != '\n' && str[i] != '\0')
	{
		outputline[i] = str[i];
		i++;
	}
	outputline[i] = str[i];
	outputline[i + 1] = '\0';
	return (outputline);
}

char	*get_next_line(int fd)
{
	char		*outputline;
	static char	*mystring;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	mystring = read_to_string(fd, mystring);
	if (!mystring)
		return (0);
	if (!mystring[0])
		outputline = 0;
	else
		outputline = output_line(mystring);
	mystring = move_on(mystring);
	return (outputline);
}
