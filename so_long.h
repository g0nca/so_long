/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggomes-v <ggomes-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:27:35 by ggomes-v          #+#    #+#             */
/*   Updated: 2025/03/11 12:46:55 by ggomes-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "minilibx-linux/mlx.h"
#include "minilibx-linux/mlx_int.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

int		main(int ac, char **av);

//------------>checks.c<-----------------
int		check(int ac, char **av);
int		check_filename(char **av);
int		check_is_rectangular(char **av);
int		is_map_rectangular(int fd, int *first_line_length);
char     *directory_filename(char **av);

int     walls_map(char **av);
void    msg_error();

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
