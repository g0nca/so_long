/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggomes-v <ggomes-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:46:59 by ggomes-v          #+#    #+#             */
/*   Updated: 2025/03/10 16:37:26 by ggomes-v         ###   ########.fr       */
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
    else
        return (1);
    return (0);
}
int     check_is_retangular(char **av)
{
    int     fd;
    char    *test;
    
    fd = open(ft_strjoin("./maps/", av[1]), O_RDONLY);
    if (fd == -1)
        return (1);
    test = get_next_line(fd);
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
