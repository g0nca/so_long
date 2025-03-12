/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggomes-v <ggomes-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 10:39:53 by ggomes-v          #+#    #+#             */
/*   Updated: 2025/03/12 11:22:45 by ggomes-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    ft_error(char *s)
{
    ft_printf("ERROR:");
    ft_printf(s);
    exit(EXIT_FAILURE);
}

int	ft_checkber(char **argv)
{
	static int	a;
	char		*str;
	int			b;

	str = ".ber";
	while (argv[1][a])
	{
		b = 0;
		while (argv[1][a] == str[b])
		{
			a++;
			b++;
			if (argv[1][a] == '\0' && str[b] == '\0')
				return (1);
			else if ((argv[1][a] == '\0' && str[b] != '\0')
				|| (argv[1][a] != '\0' && str[b] == '\0'))
				return (0);
		}
		a++;
	}
	return (0);
}

t_map *map(void)
{
	static t_map	map;

	return (&map);
}