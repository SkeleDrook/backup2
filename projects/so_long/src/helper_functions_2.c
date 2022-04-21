/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohulik <ohulik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 15:23:55 by ohulik            #+#    #+#             */
/*   Updated: 2022/04/20 22:12:24 by ohulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

char	*ft_itoa(int n)
{
	char			*chars;
	int				nbr_chars;
	int				sign;
	unsigned int	number;

	sign = 0;
	nbr_chars = ft_count_positions(n);
	chars = (char *)malloc((nbr_chars + 1) * sizeof(char));
	if (!(chars))
		return (NULL);
	chars[nbr_chars--] = '\0';
	number = n;
	if (n < 0)
	{
		sign = 1;
		number = n * -1;
	}
	ft_add_to_list(chars, number, nbr_chars);
	if (sign)
		chars[0] = '-';
	return (chars);
}

int	ft_count_positions(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

void	ft_add_to_list(char *lst_chars, unsigned int number, int count)
{
	while (count >= 0)
	{
		lst_chars[count] = number % 10 + '0';
		number /= 10;
		count--;
	}
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}
