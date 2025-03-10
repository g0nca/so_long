/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggomes-v <ggomes-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:15:02 by ggomes-v          #+#    #+#             */
/*   Updated: 2025/03/10 16:43:22 by ggomes-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*newline(char *str)
{
	int		i;
	int		j;
	char	*newline;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	newline = (char *)malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!newline)
		return (NULL);
	i++;
	j = 0;
	while (str[i])
		newline[j++] = str[i++];
	newline[j] = '\0';
	free(str);
	return (newline);
}

char	*extract_line(char *str)
{
	int		i;
	char	*line;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*read_file(int fd, char *str)
{
	char	*buffer;
	int		read_bytes;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(str, '\n') && read_bytes > 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[read_bytes] = '\0';
		str = ft_strjoin(str, buffer);
	}
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = read_file(fd, str);
	if (!str)
		return (NULL);
	if (str[0] == '\0')
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	line = extract_line(str);
	if (!line)
		return (NULL);
	str = newline(str);
	return (line);
}
/*
int main(void)
{
    int i;
    char *line;

    int fd = open("test.txt", O_RDONLY);
    if (fd == -1)
    {
		printf("╔════════════════════════════════════╗\n");
    	printf("║  ⚠️  \033[1;31m| Erro ao Abrir o Ficheiro !!!\033[0m ║\n");
    	printf("╚════════════════════════════════════╝\n");
        return (0);
    }
    i = 0;
    line = get_next_line(fd);
    while (line != 0)
    {
        printf("LINE[%d]:%s", i, line);
        free(line);
        line = get_next_line(fd);
        i++;
    }
    close(fd);
    return (0);
}
*/
