/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggomes-v <ggomes-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:29:05 by ggomes-v          #+#    #+#             */
/*   Updated: 2025/03/13 16:15:47 by ggomes-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	setup_map(void)
{
	ft_bzero(map(), sizeof(t_map));
	map()->map = NULL;
	map()->map_copy = NULL;
	map()->hei = 32;
	map()->wid = 32;
	map()->mlx = NULL;
	map()->mlx_win = NULL;
	map()->size = 64;
}

int		main(int ac, char **av)
{
	if (ac != 2)
		ft_error("Error\nInvalid Number of Arguments");
	if (ft_checkber(av) == 0)
		ft_error("Error\nInvalid file extension");
	setup_map();
	if (!ft_check(av))
		ft_startgame();
	ft_freemap();
	return (0);
}