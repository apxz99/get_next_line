/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarayapa <sarayapa@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 08:19:15 by sarayapa          #+#    #+#             */
/*   Updated: 2025/10/09 10:12:37 by sarayapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	char	*str = calloc(1, 1);
	int	fd1 = open("main.c", O_RDONLY);
	int	fd2 = open("hello", O_RDONLY);
	while (str != NULL) {
		free(str);
		str = get_next_line(fd2);
		printf("%s", str);
		free(str);
		str = get_next_line(fd1);
		printf("%s", str);
	}
	free(str);
	close(fd1);
	return (0);
}
