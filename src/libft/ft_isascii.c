/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaresov <lmaresov@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 17:12:56 by lmaresov          #+#    #+#             */
/*   Updated: 2023/08/31 18:06:58 by lmaresov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include<stdio.h>
*/
int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
/*
int main(void)
{
    char    c;
    char    result;
    int     d;
    
    c = 'a';
    result = ft_isascii(c);
    printf("%d\n", result);

    c = '0';
    result = ft_isascii(c);
    printf("%d\n", result);

    c = '+';
    result = ft_isascii(c);
    printf("%d\n", result);

    d = 250;
    result = ft_isascii(d);
    printf("%d\n", result);
    
    return (0);
}
*/
