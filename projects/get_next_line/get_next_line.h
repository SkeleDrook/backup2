/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohulik <ohulik@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 07:44:13 by ohulik            #+#    #+#             */
/*   Updated: 2022/03/14 18:30:45 by ohulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

size_t	slen(const char *s);
char	*ft_strjoin(char *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*get_next_line(int fd);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_malloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);

#endif