/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarayapa <sarayapa@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 16:45:16 by sarayapa          #+#    #+#             */
/*   Updated: 2025/10/03 09:25:54 by sarayapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# define MAX_FD 1024

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdio.h>

char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char *str, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
int		ft_putstr(char *str);
void	checkbuffer(char *(*buffer), char *(*temp));
char	*ft_findnl(const char *src, size_t *i);
char	*get_next_line(int fd);

#endif