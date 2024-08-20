/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseyun <junseyun@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 13:58:12 by junseyun          #+#    #+#             */
/*   Updated: 2024/04/17 16:44:14 by junseyun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static ssize_t	check_size(int fd, char *read_buf)
{
	ssize_t	size;

	size = read(fd, read_buf, BUFFER_SIZE);
	if (size < 0)
	{
		free(read_buf);
		read_buf = 0;
		return (-1);
	}
	read_buf[size] = 0;
	return (size);
}

static char	*end_line(char **buffer, char *read_buf)
{
	char	*line;

	free(read_buf);
	read_buf = 0;
	if (ft_strlen(*buffer) == 0)
	{
		free(*buffer);
		*buffer = 0;
		return (0);
	}
	else
	{
		line = *buffer;
		*buffer = 0;
		return (line);
	}
}

static char	*read_front_line(char *buffer)
{
	int		i;
	int		len;
	char	*new_str;

	i = 0;
	len = 1;
	while (buffer[i++] != '\n')
		len++;
	new_str = (char *)malloc(sizeof(char) * (len + 1));
	if (!(new_str))
		return (0);
	i = 0;
	while (i < len)
	{
		new_str[i] = buffer[i];
		i++;
	}
	new_str[i] = 0;
	return (new_str);
}

static char	*read_line(char **buffer, char *read_buf)
{
	char	*temp;
	char	*read_line;

	temp = (*buffer);
	read_line = read_front_line(*buffer);
	if (!read_line)
		return (0);
	*buffer = ft_strdup(ft_strchr(*buffer, '\n') + 1);
	if (!(*buffer))
		return (0);
	free(temp);
	temp = 0;
	free(read_buf);
	read_buf = 0;
	return (read_line);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*read_buf;
	ssize_t		size;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (0);
	read_buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!(read_buf))
		return (0);
	while (!(ft_strchr(buffer, '\n')))
	{
		size = check_size(fd, read_buf);
		if (size == -1)
			return (0);
		buffer = ft_strjoin(buffer, read_buf);
		if (!buffer)
			return (0);
		if (size == 0)
			return (end_line(&buffer, read_buf));
	}
	return (read_line(&buffer, read_buf));
}
