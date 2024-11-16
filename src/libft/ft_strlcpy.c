/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaresov <lmaresov@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 12:56:32 by lmaresov          #+#    #+#             */
/*   Updated: 2024/11/09 10:54:08 by lmaresov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dest, const void *src, size_t n);

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;

	src_len = ft_strlen(src);
	if (!size)
		return (src_len);
	if (size > src_len + 1)
		ft_memcpy(dst, src, src_len + 1);
	else
	{
		ft_memcpy(dst, src, size - 1);
		dst[size -1] = '\0';
	}
	return (src_len);
}
/*
int    main (void)
 {
    char src[] = "Hello";
    char dest[20] = "Ahoj";
    size_t i;
    //size_t j;
    
    i = ft_strlcpy(dest, src, 5);
    printf("delka celkoveho retezce moje: %ld\n", i);
    //j = strlcat(dest, src, 10);
    //printf("delka celkoveho retezce moje: %d\n", j);
    return (0);
     }
     */
