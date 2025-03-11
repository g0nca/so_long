/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggomes-v <ggomes-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:29:09 by ggomes-v          #+#    #+#             */
/*   Updated: 2025/03/11 12:46:30 by ggomes-v         ###   ########.fr       */
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