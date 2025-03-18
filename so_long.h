/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggomes-v <ggomes-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:27:35 by ggomes-v          #+#    #+#             */
/*   Updated: 2025/03/18 11:40:06 by ggomes-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include <X11/keysym.h>
#include <X11/X.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "minilibx-linux/mlx.h"
#include "minilibx-linux/mlx_int.h"

#define KEY_ESC 65307
#define KEY_W 119
#define KEY_A 97
#define KEY_S 115
#define KEY_D 100

#define WALL '1'
#define FLOOR '0'
#define COLLECTIBLE 'C'
#define EXIT 'E'
#define PLAYER 'P'

typedef struct s_map
{
	int		collectible;
	int		wall;
	int		player;
	int		exit;
	int		width;
	int		height;
	int		px;
	int		py;
	int		cc;
	int		ec;
	int		exitx;
	int		exity;
	char	**map;
	char	**map_copy;
	void	*wall_img;
	void	*floor_img;
	void	*player_right;
	void	*player_left;
	int		side;
	void	*collectible_img;
	void	*exit_img;
	void	*exitwin_img;
	int		hei;
	int		wid;
	void	*mlx;
	void	*mlx_win;
	int		size;
	int		moves;
}								t_map;

//  so_long.c
int		main(int ac, char **av);
void	setup_map(void);

//	ft_check.c
int	ft_check(char **argv);
int	ft_checkmap(char **argv);
char	**ft_mapcopy(char **argv);
char	**ft_map(char **argv);

//	ft_check2.c
int	ft_countobjects(void);
int	ft_checkwalls(void);
int	ft_checkobjects(void);
int	ft_checkwidth(void);

//	ft_check3.c
int	flood_fill(int x, int y);
void	ft_checkppos(void);

//	startgame.c
int	ft_startgame(void);
void render_map();
int	ft_game_destroy(void);
void	render_pixel(char element, int x, int y);
int	ft_keypress(int keysym);
void	load_images(void);

//	moves.c
int	ft_checkmove(char a, int x, int y);
void	ft_moved(void);
void	ft_movea(void);
void	ft_moves(void);
void	ft_movew(void);
void	is_collectible_exit(void);

//	utils.c
void    ft_error(char *s);
int	ft_checkber(char **argv);
t_map *map(void);
void	ft_freemap(void);

//	bonus.c
void    print_player_status(void);

//	libft
size_t	ft_strlen(const char *s);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *s, int c, size_t n);
char	*ft_strdup(const char *s);
char	*ft_itoa(int n);

//  get_next_line
char	*get_next_line(int fd);
char	*read_file(int fd, char *str);
char	*extract_line(char *str);
char	*newline(char *str);

char	*ft_strjoin(char *s1, char *s2);
char	*ft_strjoin_second(char *s1, char *s2, char *str1);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *str, int c);

//  ft_printf
int	ft_printf(const char *format, ...);
int	ft_putchar(int c);
int	ft_putnbr(int n);
int	ft_putstr(char *str);
int	ft_unsigned_int(unsigned int n);
int	ft_pointeraddress(unsigned long p);
int	ft_hexadecimal(unsigned long nbr, char str);

#endif
