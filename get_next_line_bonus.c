/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarayapa <sarayapa@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 16:47:27 by sarayapa          #+#    #+#             */
/*   Updated: 2025/10/03 09:24:56 by sarayapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_findnl(const char *src, size_t *i)
{
	while (src[(*i)] && src[(*i)] != '\n')
		(*i)++;
	if (src[(*i)] == '\n')
		return ((char *)(src + (*i) + 1));
	return (NULL);
}

char	*ft_substr_free(char *str, unsigned int start, size_t len)
{
	size_t	i;
	size_t	slen;
	char	*sub;

	if (!str)
		return (NULL);
	slen = ft_strlen(str);
	if (start >= slen)
		return (free(str), ft_strdup(""));
	if (len > slen - start)
		len = slen - start;
	sub = malloc(len + 1);
	if (!sub)
		return (free(str), NULL);
	i = 0;
	while (i < len)
	{
		sub[i] = str[start + i];
		i++;
	}
	sub[i] = '\0';
	free(str);
	return (sub);
}

void	checkbuffer(char *(*buffer), char *(*temp))
{
	if (!(*buffer))
		(*buffer) = ft_strdup("");
	(*temp) = ft_strdup((*buffer));
	free((*buffer));
	(*buffer) = NULL;
}

int	readline(int fd, char *(*temp))
{
	int		bytes_read;
	char	*old;
	char	*buff;

	buff = malloc((BUFFER_SIZE + 1) * (sizeof(char)));
	bytes_read = 1;
	while (!ft_strchr((*temp), '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(buff), -1);
		buff[bytes_read] = '\0';
		old = (*temp);
		(*temp) = ft_strjoin((*temp), buff);
		free(old);
	}
	return (free(buff), bytes_read);
}

char	*get_next_line(int fd)
{
	static char	*buffer[MAX_FD];
	char		*temp;
	size_t		i;
	int			bytes_read;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	checkbuffer(&buffer[fd], &temp);
	bytes_read = readline(fd, &temp);
	if (bytes_read < 0)
		return (free(temp), NULL);
	free(buffer[fd]);
	if (ft_findnl(temp, &i))
		buffer[fd] = ft_strdup(ft_findnl(temp, &i));
	else
		buffer[fd] = ft_strdup("");
	if (!buffer[fd])
		return (free(temp), NULL);
	temp = ft_substr_free(temp, 0, i + 1);
	if (!temp || temp[0] == '\0')
		return (free(temp), NULL);
	return (temp);
}
