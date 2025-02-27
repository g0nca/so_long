/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggomes-v <ggomes-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:46:59 by ggomes-v          #+#    #+#             */
/*   Updated: 2025/02/27 16:34:37 by ggomes-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int    check(int ac, char **av)
{
    if (ac == 2)
    {
        if (check_filename(av) == 1)
            error();
    }
    else
        return (1);
    return (0);
}

int     check_filename(char **av)
{
    int i;
    int j;
    char *type;

    i = ft_strlen(av[1]);
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