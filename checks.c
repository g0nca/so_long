/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggomes-v <ggomes-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:46:59 by ggomes-v          #+#    #+#             */
/*   Updated: 2025/03/11 11:58:08 by ggomes-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int    check(int ac, char **av)
{
    if (ac == 2)
    {
        if (check_filename(av) == 1)
            return (1);
        if (check_is_retangular(av) == 1)
            return (1);
    }
    return (0);
}
int     check_is_retangular(char **av)
{
    int     fd;
    char    *path;
    char    *buffer;
    int     first_line_len = -1;
    int     current_line_len;
    int     is_rectangular = 0;

    path = ft_strjoinV2("./maps", av[1]);
    if (!path)
        return (1);
    fd = open(path, O_RDONLY);
    free(path);
    if (fd == -1)
        return (1);
    buffer = get_next_line(fd);
    if (buffer)
    {
        first_line_len = ft_strlen(buffer);
        if (buffer[first_line_len - 1] == '\n')
            first_line_len--;
    }
    while (buffer)
    {
        current_line_len = ft_strlen(buffer);
        if (current_line_len > 0 && buffer[current_line_len - 1] == '\n')
            current_line_len--;
        if(current_line_len != first_line_len)
        {
            is_rectangular = 1;
            free(buffer);
            break ;
        }
        free(buffer);
        buffer = get_next_line(fd);
    }
    if (is_rectangular == 1)
    {
        buffer = get_next_line(fd);
        while (buffer)
        {
            free(buffer);
            buffer = get_next_line(fd);
        }
        return (1);
    }
    free(buffer);
    close(fd);
    return (0);
}

int     check_filename(char **av)
{
    int i;
    int j;
    char *type;

    i = ft_strlen(av[1]) - 4;
    j = 0;
    type = ".ber";
    while (av[1][i])
    {
        if (av[1][i] == type[j])
        {
            i++;
            j++;
        }
        else
            return (1);
    }
    return (0);
}
