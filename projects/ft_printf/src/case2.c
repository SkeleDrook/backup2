/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohulik <ohulik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 19:04:42 by ohulik            #+#    #+#             */
/*   Updated: 2022/01/23 21:58:49 by ohulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_num_hex(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

int	case_lxux(unsigned int shape, int sign)
{
	char						*str_hex;
	int							i;
	int							char_count;

	char_count = 0;
	if (shape == 0)
		return (write(1, "0", 1));
	i = 0;
	i = ft_num_hex(shape);
	str_hex = malloc(sizeof(char) * i + 1);
	str_hex[i] = '\0';
	while (shape != 0)
	{
		if ((shape % 16) > 9)
			str_hex[--i] = (shape % 16) + sign - 10 - 23 ;
		else
			str_hex[--i] = (shape % 16) + '0';
		shape /= 16;
	}
	char_count = case_s(str_hex);
	free(str_hex);
	return (char_count);
}
