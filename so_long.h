/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggomes-v <ggomes-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:27:35 by ggomes-v          #+#    #+#             */
/*   Updated: 2025/03/11 16:23:03 by ggomes-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "minilibx-linux/mlx.h"
#include "minilibx-linux/mlx_int.h"

/*typedef struct s_game
{
    void        *mlx;       // Ponteiro MLX
    void        *win;       // Janela MLX
    t_map       map;        // Mapa do jogo
    t_player    player;     // Info do player
    int         collectibles; // Total de colecionáveis no mapa
    void        *img_wall;  // Textura de parede
    void        *img_floor; // Textura do chão
    void        *img_player; // Textura do player
    void        *img_exit;   // Textura da saída
    void        *img_collect; // Textura do colecionável
}               t_game;

typedef struct s_player
{
    int x;       // Posição X (coluna)
    int y;       // Posição Y (linha)
    int moves;   // Contador de movimentos feitos
    int items;   // Colecionáveis apanhados
}               t_player;

typedef struct s_map
{
    char    **matrix;      // Mapa lido linha a linha
    int     width;         // Largura (número de colunas)
    int     height;        // Altura (número de linhas)
    int     player_count;  // Quantidade de 'P' encontrados
    int     exit_count;    // Quantidade de 'E' encontrados
    int     collect_count; // Quantidade de 'C' encontrados
    int     player_x;      // Posição inicial do jogador X
    int     player_y;      // Posição inicial do jogador Y
}               t_map;
*/

int		main(int ac, char **av);

//------------>checks.c<-----------------
int		check(int ac, char **av);
int		check_filename(char **av);
int		check_is_rectangular(char **av);
int		is_map_rectangular(int fd, int *first_line_length);

int     walls_map(char **av);
int     walls_map2(int  fd);
int walls_map_first_line(char *buffer, int  line_len);
int walls_map_middle_line(char *buffer, int current_len, int fd);

void    msg_error();
int     count_file_lines(int fd);
char     *directory_filename(char **av);

char	**ft_split(char const *s, char c);
void	*free_array(char **array);
char	*if_null(char **array, int a);
char	*save_words(const char *s, char c);
int	count_words(char const *str, char c);

char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin_second(char *s1, char *s2, char *str1);

char	*ft_strjoinV2(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);



#endif
