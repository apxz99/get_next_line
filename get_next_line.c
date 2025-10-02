/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarayapa <sarayapa@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 16:47:27 by sarayapa          #+#    #+#             */
/*   Updated: 2025/10/02 11:34:10 by sarayapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_findnl(const char *src, size_t *i)
{
	while (src[(*i)] && src[(*i)] != '\n')
		(*i)++;
	if (src[(*i)] == '\n')
		return ((char *)(src + (*i) + 1));
	return (NULL);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	slen;
	char	*sub;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen)
		return (free(s), ft_strdup(""));
	if (len > slen - start)
		len = slen - start;
	sub = malloc(len + 1);
	if (!sub)
		return (free(s), NULL);
	i = -1;
	while (++i < len)
		sub[i] = s[start + i];
	sub[i] = '\0';
	free(s);
	return (sub);
}

void	checkstash(char *(*stash), char *(*temp))
{
	if (!(*stash))
		(*stash) = ft_strdup("");
	(*temp) = ft_strdup((*stash));
	free((*stash));
	(*stash) = NULL;
}

int	readline(int fd, char *buff, char *(*temp))
{
	int		bytes_read;
	char	*old;

	bytes_read = 1;
	while (!ft_strchr((*temp), '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read < 0)
			return (-1);
		buff[bytes_read] = '\0';
		old = (*temp);
		(*temp) = ft_strjoin((*temp), buff);
		free(old);
	}
	return (bytes_read);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		buff[BUFFER_SIZE + 1];
	char		*temp;
	size_t		i;
	int			bytes_read;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	checkstash(&stash, &temp);
	bytes_read = readline(fd, buff, &temp);
	if (bytes_read < 0)
		return (NULL);
	free(stash);
	if (ft_findnl(temp, &i))
		stash = ft_strdup(ft_findnl(temp, &i));
	else
		stash = ft_strdup("");
	temp = ft_substr(temp, 0, i + 1);
	if (!temp || temp[0] == '\0')
	{
		free(temp);
		return (NULL);
	}
	return (temp);
}
