/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggomes-v <ggomes-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:21:24 by ggomes-v          #+#    #+#             */
/*   Updated: 2025/03/19 12:12:03 by ggomes-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_movew(void)
{
	mlx_put_image_to_window(map()->mlx, map()->mlx_win,
		map()->floor_img, map()->px * map()->size, map()->py * map()->size);
	map()->map[map()->py][map()->px] = FLOOR;
	map()->py--;
	is_collectible_exit();
	map()->map[map()->py][map()->px] = PLAYER;
	mlx_put_image_to_window(map()->mlx, map()->mlx_win,
		map()->player_right, map()->px * map()->size, map()->py * map()->size);
	map()->moves++;
	ft_printf("Player Moves: %d\n", map()->moves);
}

void	ft_moves(void)
{
	mlx_put_image_to_window(map()->mlx, map()->mlx_win,
		map()->floor_img, map()->px * map()->size, map()->py * map()->size);
	map()->map[map()->py][map()->px] = FLOOR;
	map()->py++;
	is_collectible_exit();
	map()->map[map()->py][map()->px] = PLAYER;
	mlx_put_image_to_window(map()->mlx, map()->mlx_win,
		map()->player_right, map()->px * map()->size, map()->py * map()->size);
	map()->moves++;
	ft_printf("Player Moves: %d\n", map()->moves);
}

void	ft_movea(void)
{
	mlx_put_image_to_window(map()->mlx, map()->mlx_win,
		map()->floor_img, map()->px * map()->size, map()->py * map()->size);
	map()->map[map()->py][map()->px] = FLOOR;
	map()->px--;
	is_collectible_exit();
	map()->map[map()->py][map()->px] = PLAYER;
	mlx_put_image_to_window(map()->mlx, map()->mlx_win,
		map()->player_right, map()->px * map()->size, map()->py * map()->size);
	map()->moves++;
	ft_printf("Player Moves: %d\n", map()->moves);
}

void	ft_moved(void)
{
	mlx_put_image_to_window(map()->mlx, map()->mlx_win,
		map()->floor_img, map()->px * map()->size, map()->py * map()->size);
	map()->map[map()->py][map()->px] = FLOOR;
	map()->px++;
	is_collectible_exit();
	map()->map[map()->py][map()->px] = PLAYER;
	mlx_put_image_to_window(map()->mlx, map()->mlx_win,
		map()->player_right, map()->px * map()->size, map()->py * map()->size);
	map()->moves++;
	ft_printf("Player Moves: %d\n", map()->moves);
}

int	ft_checkmove(char a, int x, int y)
{
	if (map()->map[y][x] == WALL)
		return (0);
	if (map()->map[y][x] == EXIT && map()->collectible != 0)
		return (0);
	if (a == 'w')
		ft_movew();
	if (a == 's')
		ft_moves();
	if (a == 'a')
		ft_movea();
	if (a == 'd')
		ft_moved();
	return (1);
}
