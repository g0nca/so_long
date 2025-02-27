/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggomes-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:43:02 by ggomes-v          #+#    #+#             */
/*   Updated: 2024/11/04 14:47:56 by ggomes-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}
/*
#include <stdio.h>
int main(void)
{
    const char str[] = "goncalo";
    const char ch = 'c';
    char *result = ft_strchr(str,ch);
    if(result != NULL)
	printf("Caracter %c encontrado na posicao %ld\n", ch, result - str);
    else
	printf("O caracter '%c' nao foi encontado na string\n", ch); 
    return(0);
}
*/
