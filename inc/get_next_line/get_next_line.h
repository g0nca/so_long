/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggomes-v <ggomes-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:16:09 by ggomes-v          #+#    #+#             */
/*   Updated: 2025/03/18 16:33:28 by ggomes-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/libft.h"

char	*get_next_line(int fd);
char	*read_file(int fd, char *str);
char	*extract_line(char *str);
char	*newline(char *str);
char	*ft_strjoingnl(char *s1, char *s2);
char	*ft_strjoin_second(char *s1, char *s2, char *str1);
size_t	ft_strlengnl(const char *s);
char	*ft_strchrgnl(const char *str, int c);
#endif
