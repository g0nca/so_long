/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggomes-v <ggomes-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:50:46 by ggomes-v          #+#    #+#             */
/*   Updated: 2025/03/19 13:19:19 by ggomes-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_images(void)
{
	map()->mlx_win = mlx_new_window(map()->mlx, ((map()->width) * map()->size),
		(map()->height * map()->size), "Game");
	map()->wall_img = mlx_xpm_file_to_image(map()->mlx,
		"./assets/textures/wall.xpm", &map()->wid, &map()->hei);
	map()->floor_img = mlx_xpm_file_to_image(map()->mlx,
		"./assets/textures/floor.xpm", &map()->wid, &map()->hei);
	map()->player_right = mlx_xpm_file_to_image(map()->mlx,
		"./assets/textures/player_right.xpm", &map()->wid, &map()->hei);
	map()->player_left = mlx_xpm_file_to_image(map()->mlx,
		"./assets/textures/player_left.xpm", &map()->wid, &map()->hei);
	map()->collectible_img = mlx_xpm_file_to_image(map()->mlx,
		"./assets/textures/collectible.xpm", &map()->wid, &map()->hei);
	map()->exit_img = mlx_xpm_file_to_image(map()->mlx,
		"./assets/textures/exit.xpm", &map()->wid, &map()->hei);
	map()->exitwin_img = mlx_xpm_file_to_image(map()->mlx,
		"./assets/textures/exit1.xpm", &map()->wid, &map()->hei);
}
