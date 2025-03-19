/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggomes-v <ggomes-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:54:52 by ggomes-v          #+#    #+#             */
/*   Updated: 2025/03/19 12:45:58 by ggomes-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	flood_fill(int x, int y)
{
	if (map()->map_copy[y][x] == '1' || map()->map_copy[y][x] == 'X')
		return (1);
	if (map()->map_copy[y][x] == 'C')
		map()->cc++;
	if (map()->map_copy[y][x] == 'E')
	{
		if (map()->cc == map()->collectible)
			map()->ec++;
		return (0);
	}
	map()->map_copy[y][x] = 'X';
	flood_fill(x + 1, y);
	flood_fill(x - 1, y);
	flood_fill(x, y + 1);
	flood_fill(x, y - 1);
	return (0);
}

void	ft_checkppos(void)
{
	int	x;
	int	y;

	y = -1;
	while (++y < map()->height)
	{
		x = -1;
		while (++x < map()->width)
		{
			if (map()->map[y][x] == 'P')
			{
				map()->px = x;
				map()->py = y;
			}
			if (map()->map[y][x] == 'E')
			{
				map()->exitx = x;
				map()->exity = y;
			}
		}
	}
}
