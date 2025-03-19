/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggomes-v <ggomes-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 11:38:57 by ggomes-v          #+#    #+#             */
/*   Updated: 2025/03/19 12:44:34 by ggomes-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_player_status(void)
{
	char	*moves;
	char	*collectible;

	moves = ft_itoa(map()->moves);
	collectible = ft_itoa(map()->collectible);
	mlx_put_image_to_window(map()->mlx, map()->mlx_win, map()->wall_img, 64, 0);
	mlx_string_put(map()->mlx, map()->mlx_win,
		10, 20, 0xFFFFFF, "Movimentos: ");
	mlx_string_put(map()->mlx, map()->mlx_win,
		80, 20, 0xFFFFFF, moves);
	mlx_string_put(map()->mlx, map()->mlx_win,
		10, 40, 0xFFFFFF, "Coletaveis :");
	mlx_string_put(map()->mlx, map()->mlx_win, 85, 40, 0xFFFFFF, collectible);
	free(moves);
	free(collectible);
	moves = NULL;
	collectible = NULL;
}

void	is_collectible_exit(void)
{
	if (map()->map[map()->py][map()->px] == COLLECTIBLE)
	{
		map()->collectible--;
		if (map()->collectible == 0)
			mlx_put_image_to_window(map()->mlx, map()->mlx_win,
				map()->exitwin_img,
				map()->exitx * map()->size, map()->exity * map()->size);
	}
	if (map()->map[map()->py][map()->px] == EXIT)
	{
		map()->moves++;
		ft_printf("Player Moves: %d\nYou Win!\n", map()->moves);
		ft_game_destroy();
	}
}
