/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarayapa <sarayapa@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 16:47:27 by sarayapa          #+#    #+#             */
/*   Updated: 2025/10/02 08:56:21 by sarayapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (!src || !dst)
		return (0);
	if (size == 0)
		return (ft_strlen(src));
	while ((size - 1 > i) && src[i])
	{
		*(dst + i) = *(src + i);
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

char	*ft_findnl(const char *src)
{
	size_t	i;

	i = 0;
	while (src[i] && src[i] != '\n')
		i++;
	if (src[i] == '\n')
		return ((char *)(src + i + 1));
	return (NULL);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*dst;

	i = 0;
	j = 0;
	k = 0;
	dst = malloc(ft_strlen(s1) - ft_strlen(set) + 1);
	while (i < (ft_strlen(s1) - ft_strlen(set)))
	{
		if (s1[j] != set[k])
		{
			dst[i] = s1[j];
			i++;
			j++;
		}
		else
		{
			j++;
			k++;
		}
	}
	dst[i] = '\0';
	return (dst);
}

char	*get_next_line(int fd)
{
	static char 	buff[BUFFER_SIZE];
	char 			*rest;
	char			*temp;
	size_t			i;

	i = 0;
	temp = ft_strdup("");
	while(!(ft_strchr(temp, '\n')))
	{
		temp = ft_strjoin(temp, buff);
		read(fd, buff, BUFFER_SIZE);
		i++;
	}
	rest = ft_findnl(temp);
	if (rest)
	{
		ft_strlcpy(buff, rest, BUFFER_SIZE);
	}
	else
		buff[0] = '\0';
	printf("buff : %s\n", buff);
	return (ft_strtrim(temp, "\n"));
}