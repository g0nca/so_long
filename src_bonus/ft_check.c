/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggomes-v <ggomes-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:46:20 by ggomes-v          #+#    #+#             */
/*   Updated: 2025/03/19 13:28:04 by ggomes-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_map(char **argv)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	map()->map = malloc(sizeof(char *) * (map()->height + 1));
	if (!map()->map)
		return (0);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map()->map[i] = ft_strdup(line);
		i++;
		free(line);
	}
	map()->map[i] = NULL;
	close(fd);
	return (map()->map);
}

char	**ft_mapcopy(char **argv)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	map()->map_copy = malloc(sizeof(char *) * (map()->height + 1));
	if (!map()->map_copy)
		return (0);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map()->map_copy[i] = ft_strdup(line);
		i++;
		free(line);
	}
	map()->map_copy[i] = NULL;
	close(fd);
	return (map()->map_copy);
}

int	ft_checkmap(char **argv)
{
	int				fd;
	char			*line;
	static int		j;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (2);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (ft_strchr(line, '\n'))
			map()->width = ft_strlen(line) - 1;
		else
			map()->width = ft_strlen(line);
		if (map()->width == 0)
			j = 2;
		map()->height++;
		free(line);
	}
	close(fd);
	return (j);
}

int	ft_check(char **argv)
{
	if (!ft_checkmap(argv))
	{
		map()->map = ft_map(argv);
		map()->map_copy = ft_mapcopy(argv);
		if (!ft_countobjects() && !ft_checkwidth() && !ft_checkobjects())
		{
			ft_checkppos();
			flood_fill(map()->px, map()->py);
			ft_printf("collectible: %d\n", map()->collectible);
			if (map()->ec != 1 || map()->cc != map()->collectible)
				return (ft_printf("%s", "Error\nInvalid Path\n"));
		}
		else
			return (1);
	}
	else
		return (ft_printf("%s", "Error\nInvalid map\n"));
	return (0);
}
