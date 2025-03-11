/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggomes-v <ggomes-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:29:09 by ggomes-v          #+#    #+#             */
/*   Updated: 2025/03/11 15:27:32 by ggomes-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    msg_error()
{
    write(1, "ERROR", 5);
}
char     *directory_filename(char **av)
{
    char    *path;

    path = ft_strjoinV2("./maps", av[1]);
    return (path);
}
int     count_file_lines(int fd)
{
    char *buffer;
    int i;
    
    i = 1;
    buffer = get_next_line(fd);
    while (buffer)
    {
        i++;
        free(buffer);
        buffer = get_next_line(fd);
    }
    return (i);
}