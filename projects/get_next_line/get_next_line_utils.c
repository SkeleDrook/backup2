/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohulik <ohulik@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 07:44:17 by ohulik            #+#    #+#             */
/*   Updated: 2022/03/14 19:02:15 by ohulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;
	size_t	length;

	if (s == NULL)
		return (NULL);
	i = 0;
	length = slen(s);
	if (start >= length || !s)
		len = 0;
	else if (length < (start + len))
		len = length - start;
	dest = malloc(len + 1);
	if (dest != NULL)
	{
		while (i < len && s[i])
		{
			dest[i] = s[start + i];
			i++;
		}
		dest[i] = '\0';
	}
	return (dest);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*dest;
	size_t	len;
	size_t	i;
	size_t	j;

	j = 0;
	i = -1;
	if (!s1 || !s2)
		return (NULL);
	len = slen(s1) + slen(s2);
	dest = malloc(len + 1);
	if (!dest)
		return (NULL);
	while (s1[++i] != '\0')
		dest[i] = s1[i];
	while (s2[j] != '\0')
	{
		dest[i + j] = s2[j];
		j++;
	}
	dest[i + j] = '\0';
	free(s1);
	return (dest);
}

void	ft_bzero(void *s, size_t n)
{
	char	*pchar1;

	pchar1 = s;
	while (n > 0)
	{
		*pchar1 = '\0';
		n--;
		pchar1++;
	}
}

void	*ft_malloc(size_t count, size_t size)
{
	void			*ret_str;
	unsigned char	*tmp_str;

	ret_str = malloc(count * size);
	if (!ret_str)
		return (NULL);
	tmp_str = ret_str;
	*tmp_str = '\0';
	return (ret_str);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*pdst;
	char	*psrc;

	i = 0;
	if (!dst || !src)
		return (NULL);
	pdst = (char *)dst;
	psrc = (char *)src;
	if (psrc < pdst)
	{
		while (len > 0)
		{
			pdst[len] = psrc[len];
			len--;
		}
		return (dst);
	}
	while (i < len)
	{
		pdst[i] = psrc[i];
		i++;
	}
	return (dst);
}
