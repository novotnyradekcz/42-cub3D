/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 20:29:11 by rnovotny          #+#    #+#             */
/*   Updated: 2024/11/09 13:00:54 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_end(const char *str, char end)
{
	int	n;

	if (!str)
		return (0);
	n = 0;
	while (str[n] != '\0' && str[n] != end)
		n++;
	return (n);
}

int	ft_strchr_find(const char *s, int c)
{
	int		i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != 0)
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	int		len1;
	int		len2;
	int		i;
	char	*joined;

	len1 = ft_strlen_end(s1, '\0');
	len2 = ft_strlen_end(s2, '\0');
	i = 0;
	joined = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (!joined)
	{
		free(s1);
		return (0);
	}
	while (i < len1 + len2)
	{
		if (i < len1)
			joined[i] = s1[i];
		else
			joined[i] = s2[i - len1];
		i++;
	}
	joined[i] = '\0';
	free(s1);
	return (joined);
}

char	*move_on(char *str)
{
	char	*new;
	int		i;
	int		len;

	len = ft_strlen_end(str, '\n');
	if (len == (int)ft_strlen_end(str, '\0'))
	{
		free(str);
		return (0);
	}
	new = (char *)malloc((ft_strlen_end(str, '\0') - len) * sizeof(char));
	if (!new)
	{
		free(str);
		return (0);
	}
	i = 0;
	while (str[len + i + 1] != '\0')
	{
		new[i] = str[len + i + 1];
		i++;
	}
	new[i] = '\0';
	free(str);
	return (new);
}

char	*read_to_string(int fd, char *str)
{
	int		check;
	char	*buffer;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (0);
	if (ft_strchr_find(str, '\n'))
		check = 0;
	else
		check = BUFFER_SIZE;
	while (check == BUFFER_SIZE)
	{
		check = read(fd, buffer, BUFFER_SIZE);
		if (check < 0)
		{
			free(buffer);
			return (0);
		}
		buffer[check] = '\0';
		if (ft_strchr_find(buffer, '\n'))
			check = 0;
		str = ft_strjoin_gnl(str, buffer);
	}
	free(buffer);
	return (str);
}
