/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaresov <lmaresov@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 15:54:02 by lmaresov          #+#    #+#             */
/*   Updated: 2024/11/09 10:58:58 by lmaresov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*src1;
	unsigned char	*dest1;
	size_t			i;

	i = 0;
	src1 = (unsigned char *)src;
	dest1 = (unsigned char *)dest;
	while (i < n)
	{
		dest1[i] = src1[i];
		i++;
	}
	return (dest);
}
/*
int main (void)
{
    char src[] = "Hello, World";
    char cil[20];
    memcpy (cil, src, strlen(src)+1);
    printf("cilovy retezec po pouziti metodz memcpy: %s\n", cil);
    printf("\n");
    ft_memcpy (cil, src, strlen(src)+1);
    printf("cilovy retezec po pouziti moji metody memcpy: %s\n", cil);
    return (0);
}
*/
