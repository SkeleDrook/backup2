/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohulik <ohulik@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 07:44:08 by ohulik            #+#    #+#             */
/*   Updated: 2022/03/14 19:04:14 by ohulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	slen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	if (c == '\0')
		return ((char *)s + slen(s));
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}

char	*make_str(int fd, int bytes_read, char *ret_str, char **tmpstr)
{
	static char	buff[BUFFER_SIZE + 1];

	while (!ft_strchr(buff, '\n'))
	{
		if (*buff)
			ret_str = ft_strjoin(ret_str, buff);
		bytes_read = read(fd, buff, BUFFER_SIZE);
		buff[bytes_read] = '\0';
		if (bytes_read <= 0 && !(*ret_str))
		{
			free(ret_str);
			return (NULL);
		}
		if (bytes_read < BUFFER_SIZE && !ft_strchr(buff, '\n'))
		{
			ret_str = ft_strjoin(ret_str, buff);
			ft_bzero(buff, 1);
			return (ret_str);
		}
	}
	*tmpstr = ft_strjoin(ret_str, buff);
	ret_str = ft_substr(*tmpstr, 0, ((ft_strchr(*tmpstr, '\n') - *tmpstr + 1)));
	ft_memmove(buff, *tmpstr + slen(ret_str), slen(*tmpstr) - slen(ret_str));
	ft_bzero(&buff[slen(*tmpstr) - slen(ret_str)], 1);
	return (ret_str);
}

char	*get_next_line(int fd)
{
	int			bytes_read;
	char		*ret_str;
	char		*tmpstr;

	bytes_read = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ret_str = ft_malloc(sizeof(char), 1);
	tmpstr = NULL;
	ret_str = make_str(fd, bytes_read, ret_str, &tmpstr);
	if (tmpstr)
		free(tmpstr);
	if (ret_str == NULL)
		return (NULL);
	else
		return (ret_str);
}

/*number returned by read() = [n], WHILE (n > 0) so like the read() reads a 
certain ammount of characters  into a buffer that were defined in the buffer size
from the textfile pointed to by the fd and when it reads it, it checks if the 
character \n was there and if it wasn't then it keeps reading and if it IS there
then breaks the loop once you break the loop you return the line that you read
and setup thestatic variable for the next time the function is called */

/* BEHAVIORS:
- if there is nothing else to be read or an error occured return NULL
- it has to work for text file (fd[file descriptor) and (stdin[standard input])
- RETURN includes (\n) UNLESS it's eof
*/

/* TO DO:
-remove includes
-remove set value of BUFFER_SIZE (you only need it for testing)
-put get next line in file header
-all helper functions need to be in get_next_line_utils.c
-check for leaks
-Figure out behavior of Buffer Size at high values like 9999 and 10000000
-update the headers so they're not so old LMAO
*/

//read behaviors err -1 rol 0 else bytes read 
