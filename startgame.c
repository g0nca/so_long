/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   startgame.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggomes-v <ggomes-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:53:29 by ggomes-v          #+#    #+#             */
/*   Updated: 2025/03/13 14:53:44 by ggomes-v         ###   ########.fr       */
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
void	render_pixel(char element, int x, int y)
{
	if (element == WALL)
		mlx_put_image_to_window(map()->mlx, map()->mlx_win,
			map()->wall_img, x * map()->size, y * map()->size);
	else if (element == FLOOR)
		mlx_put_image_to_window(map()->mlx, map()->mlx_win,
			map()->floor_img, x * map()->size, y * map()->size);
	else if (element == PLAYER)
		mlx_put_image_to_window(map()->mlx, map()->mlx_win,
			map()->player_img, x * map()->size, y * map()->size);
	else if (element == COLLECTIBLE)
		mlx_put_image_to_window(map()->mlx, map()->mlx_win,
			map()->collectible_img, x * map()->size, y * map()->size);
	else if (element == EXIT)
		mlx_put_image_to_window(map()->mlx, map()->mlx_win,
			map()->exit_img, x * map()->size, y * map()->size);
}

void	render_map()
{
	int		i;
	int		j;
	char	element;

	i = -1;
	while (++i < map()->height)
	{
		j = -1;
		while (++j < (map()->width + 1))
		{
			element = map()->map[i][j];
			if (map()->map[i][j] == WALL)
				render_pixel(element, j, i);
			else if (map()->map[i][j] == FLOOR)
				render_pixel(element, j, i);
			else if (map()->map[i][j] == PLAYER)
				render_pixel(element, j, i);
			else if (map()->map[i][j] == COLLECTIBLE)
				render_pixel(element, j, i);
			else if (map()->map[i][j] == EXIT)
				render_pixel(element, j, i);
		}
	}
}
int	ft_keypress(int keysym)
{
	if (keysym == KEY_ESC)
		ft_game_destroy();
	if (keysym == KEY_W)
		ft_checkmove(keysym, map()->px, map()->py - 1);
	if (keysym == KEY_S)
		ft_checkmove(keysym, map()->px, map()->py + 1);
	if (keysym == KEY_A)
		ft_checkmove(keysym, map()->px - 1, map()->py);
	if (keysym == KEY_D)
		ft_checkmove(keysym, map()->px + 1, map()->py);
	return (0);
}
int	ft_startgame(void)
{
	map()->mlx = mlx_init();
	ft_printf("Welcome to So Long!\n");
	map()->mlx_win = mlx_new_window(map()->mlx, ((map()->width) * map()->size),
			(map()->height * map()->size), "Game");
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
	if (!map()->wall_img || !map()->floor_img || !map()->player_img)
		return (ft_printf("Failed loading the images ...\n"), 1);
	render_map();
	mlx_hook(map()->mlx_win, KeyPress, KeyPressMask, &ft_keypress, map());
	mlx_hook(map()->mlx_win, DestroyNotify,
		ButtonPressMask, &ft_game_destroy, map());
	mlx_loop(map()->mlx);
	return (0);
}
