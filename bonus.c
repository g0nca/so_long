/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggomes-v <ggomes-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 11:38:57 by ggomes-v          #+#    #+#             */
/*   Updated: 2025/03/18 11:39:06 by ggomes-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    print_player_status(void)
{
    mlx_put_image_to_window(map()->mlx, map()->mlx_win, map()->wall_img, 64, 0);
	mlx_string_put(map()->mlx, map()->mlx_win, 10, 20, 0xFFFFFF, "Movimentos: ");
	mlx_string_put(map()->mlx, map()->mlx_win, 80, 20, 0xFFFFFF, ft_itoa(map()->moves));
	mlx_string_put(map()->mlx, map()->mlx_win, 10, 40, 0xFFFFFF, "Coletaveis :");
	mlx_string_put(map()->mlx, map()->mlx_win, 85, 40, 0xFFFFFF, ft_itoa(map()->collectible));
}