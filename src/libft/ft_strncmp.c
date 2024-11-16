/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaresov <lmaresov@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 19:14:55 by lmaresov          #+#    #+#             */
/*   Updated: 2023/09/01 15:09:47 by lmaresov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
//#include <stdio.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (((s1[i] != '\0') || (s2[i] != '\0')) && (i < n))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char) s2[i]);
		i++;
	}
	return (0);
}
/*
int main (void)
{
	char haystack[30] = "aaabcabcd";
	//char needle[10] = "aabc";

	printf("%d \n",ft_strncmp(haystack, "aaabc", 5));
	printf("%d \n",ft_strncmp(haystack, "abcd", 9));
	printf("%d \n",ft_strncmp(haystack, "a", 1));
	return (0);
}
*/
/*
int	main(void)
{	
	int	k;
	char	s1[] = "ABC";
	char	s2[] = "ABCC";
		
	k = ft_strncmp(s1, s2, 4);
	printf("%d\n", k );
	return (0);
}
*/
