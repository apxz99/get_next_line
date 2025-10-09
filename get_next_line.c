/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarayapa <sarayapa@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 16:47:27 by sarayapa          #+#    #+#             */
/*   Updated: 2025/10/09 12:07:49 by sarayapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*checkbuffer(char **buffer, char **temp)
{
	if (!*buffer)
	{
		*buffer = ft_strdup("");
		if (!*buffer)
			return (NULL);
	}
	*temp = ft_strdup(*buffer);
	if (!*temp)
		return (NULL);
	return (*temp);
}

int	readline(int fd, char *(*temp))
{
	int		bytes_read;
	char	*old;
	char	*buff;

	if (!*temp)
	{
		*temp = ft_strdup("");
		if (!*temp)
			return (-1);
	}
	buff = malloc((BUFFER_SIZE + 1) * (sizeof(char)));
	if (!buff)
		return (-1);
	bytes_read = 1;
	while (!ft_strchr((*temp), '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(*temp);
			free(buff);
			return (-1);
		}
		buff[bytes_read] = '\0';
		old = (*temp);
		(*temp) = ft_strjoin((*temp), buff);
		free(old);
		if (!*temp)
		{
			free(buff);
			return (-1);
		}
	}
	free(buff);
	return (bytes_read);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*temp;
	char		*line;
	size_t		len;
	char		*old_buffer;

	if ((fd < 0 || BUFFER_SIZE <= 0) || (!checkbuffer(&buffer, &temp)))
		return (NULL);
	if (readline(fd, &temp) < 0)
		return (NULL);
	len = 0;
	while (temp[len] && temp[len] != '\n')
		len++;
	if (temp[len] == '\n')
		len++;
	old_buffer = buffer;
	if (temp[len])
		buffer = ft_strdup(temp + len);
	else
		buffer = ft_strdup("");
	free(old_buffer);
	if (!buffer)
	{
		free(temp);
		return (NULL);
	}
	line = ft_substr(temp, 0, len);
	free(temp);
	if (!line || line[0] == '\0')
	{
		free(line);
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	return (line);
}
