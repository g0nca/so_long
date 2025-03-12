/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   startgame.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggomes-v <ggomes-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:53:29 by ggomes-v          #+#    #+#             */
/*   Updated: 2025/03/12 16:41:34 by ggomes-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_game_destroy(void)
{
	mlx_destroy_image(map()->mlx, map()->wall_img);
	mlx_destroy_image(map()->mlx, map()->player_img);
	mlx_destroy_image(map()->mlx, map()->collectible_img);
	mlx_destroy_image(map()->mlx, map()->exit_img);
	mlx_destroy_image(map()->mlx, map()->exitwin_img);
	mlx_destroy_image(map()->mlx, map()->floor_img);
	mlx_destroy_window(map()->mlx, map()->mlx_win);
	mlx_destroy_display(map()->mlx);
	free(map()->mlx);
	ft_freemap();
	exit(0);
}

int	ft_startgame(void)
{
	map()->mlx = mlx_init();
	printf("Welcome to So Long!\n");
	map()->mlx_win = mlx_new_window(map()->mlx, ((map()->width) * map()->size),
			(map()->height * map()->size), "Bananas Slave");
	map()->wall_img = mlx_xpm_file_to_image(map()->mlx,
			"./assets/wall.xpm", &map()->wid, &map()->hei);
	map()->floor_img = mlx_xpm_file_to_image(map()->mlx,
			"./assets/floor.xpm", &map()->wid, &map()->hei);
	map()->player_img = mlx_xpm_file_to_image(map()->mlx,
			"./assets/player.xpm", &map()->wid, &map()->hei);
	map()->collectible_img = mlx_xpm_file_to_image(map()->mlx,
			"./assets/collectible.xpm", &map()->wid, &map()->hei);
	map()->exit_img = mlx_xpm_file_to_image(map()->mlx, "./assets/exit.xpm",
			&map()->wid, &map()->hei);
	map()->exitwin_img = mlx_xpm_file_to_image(map()->mlx, "./assets/exit1.xpm",
			&map()->wid, &map()->hei);
	ft_showimg();
	mlx_hook(map()->mlx_win, KeyPress, KeyPressMask, &ft_keypress, map());
	mlx_hook(map()->mlx_win, DestroyNotify,
		ButtonPressMask, &ft_game_destroy, map());
	mlx_loop(map()->mlx);
	return (0);
}