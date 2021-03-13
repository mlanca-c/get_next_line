/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 14:28:24 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/03/01 11:06:40 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next					_line.h"

char	*get_until_line(char *save)
{
	int		i;
	char	*line;

	if (!save)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!(line = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		line[i] = save[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*get_after_line(char *save)
{
	int		i;
	int		j;
	char	*s;

	if (!save)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (0);
	}
	if (!(s = (char *)malloc(sizeof(char) * (ft_strlen(save) - i + 1))))
		return (NULL);
	i++;
	j = 0;
	while (save[i])
		s[j++] = save[i++];
	s[j] = '\0';
	free(save);
	return (s);
}

int		get_next_line(int fd, char **line)
{
	static char *saved[1024];
	char		*buf;
	int			reader;

	if ((read(fd, 0, 0) == -1) | !line | BUFFER_SIZE <= 0)
		return (-1);
	if (!(buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	reader = 1;
	while (!has_return(saved[fd]) && reader != 0)
	{
		if ((reader = read(fd, buf, BUFFER_SIZE)) == -1)
		{
			free(buf);
			return (-1);
		}
		buf[reader] = '\0';
		saved[fd] = ft_strjoin(saved[fd], buf);
	}
	free(buf);
	*line = get_until_line(saved[fd]);
	saved[fd] = get_after_line(saved[fd]);
	if (reader == 0)
		return (0);
	return (1);
}
