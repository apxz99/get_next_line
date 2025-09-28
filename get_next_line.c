/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarayapa <sarayapa@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 16:47:27 by sarayapa          #+#    #+#             */
/*   Updated: 2025/09/27 13:04:37 by sarayapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	buff[BUFFER_SIZE];
	size_t	i;\

	i = 0;
	read(fd, buff, BUFFER_SIZE);

	while(ft_strchr(buff, '\n'))
	{
		read(fd, buff, BUFFER_SIZE);
		printf("%zu\n",i);
	}
	ft_putstrnl(buff);
	return (NULL);
}