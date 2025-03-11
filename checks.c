/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggomes-v <ggomes-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:46:59 by ggomes-v          #+#    #+#             */
/*   Updated: 2025/03/11 16:34:32 by ggomes-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int    check(int ac, char **av)
{
    if (ac == 2)
    {
        if (av[1] == NULL)
            return (1);
        if (check_filename(av) == 1)
            return (1);
        if (check_is_rectangular(av) == 1)
            return (1);
        if (walls_map(av) == 1)
            return (1);
    }
    return (0);
}
//Check if all lines have the same length
int is_map_rectangular(int fd, int *first_line_length)
{
    char *buffer;
    int current_line_len;
    
    buffer = get_next_line(fd);
    if (!buffer)
        return (0);
    *first_line_length = ft_strlen(buffer);
    if (buffer[*first_line_length - 1] == '\n')
        (*first_line_length)--;
    while (buffer)
    {
        current_line_len = ft_strlen(buffer);
        if (current_line_len > 0 && buffer[current_line_len - 1] == '\n')
            current_line_len--;
        if (current_line_len != *first_line_length) //No retangular
        {
            free(buffer);
            return (1);
        }
        free(buffer);
        buffer = get_next_line(fd);
    }
    return (0);
}

// Second function: opens the file and calls the first function
int check_is_rectangular(char **av)
{
    int fd;
    char *path;
    int result;
    int first_line_len;
    char *buffer;

    path = directory_filename(av);
    fd = open(path, O_RDONLY);
    free(path);
    if (fd == -1)
        return (1);
    result = is_map_rectangular(fd, &first_line_len);// Check if map is rectangular
    if (result == 1)
    {
        buffer = get_next_line(fd);
        while (buffer)
        {
            free(buffer);
            buffer = get_next_line(fd);
        }
    }
    close(fd);
    return (result);
}
int walls_map_first_line(char *buffer, int  line_len)
{
    int i;

    if (buffer[line_len - 1] == '\n')
        line_len--;
    i = 0;
    while (i < line_len)
    {
        if (buffer[i] != '1')
        {
            free(buffer);
            return (1);
        }
        i++;
    }
    return (0);
}
int walls_map_middle_line(char *buffer, int current_len, int fd)
{ 
    while (buffer)
    {
        current_len = ft_strlen(buffer);
        if (buffer[current_len - 1] == '\n')
            current_len--;
        if (buffer[0] != '1' || buffer[current_len - 1] != '1')
        {
            free(buffer);
            return (1);
        }
        free(buffer);
        buffer = get_next_line(fd);
    }
    free(buffer);
    return(0);
}
int walls_map2(int fd)
{
    char *buffer;
    int line_len = 0;
    int first_line;
    int middle_line;
    
    buffer = get_next_line(fd);
    line_len = ft_strlen(buffer);
    first_line = walls_map_first_line(buffer, line_len);
    if (first_line == 1)
        return (1);
    //n_lines = count_file_lines(fd);
    middle_line = walls_map_middle_line(buffer, line_len, fd);
    if (middle_line == 1)
        return (1);
    return (0);
}

int walls_map(char **av)
{
    int fd;
    char *path;
    char *buffer;
    int result;
    
    path = directory_filename(av);
    fd = open(path, O_RDONLY);
    free(path);
    if (fd == -1)
        return (1);
    result = walls_map2(fd);
    if (result == 1)
    {
        buffer = get_next_line(fd);
        while (buffer)
        {
            free(buffer);
            buffer = get_next_line(fd);
        }
        close(fd);
        return (1);
    }
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
