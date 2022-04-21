/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohulik <ohulik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 03:02:12 by ohulik            #+#    #+#             */
/*   Updated: 2022/01/23 21:00:46 by ohulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_num_len(unsigned	int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 10;
	}
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	char	*num;
	int		len;

	len = ft_num_len(n);
	num = (char *)malloc(sizeof(char) * (len + 1));
	if (!num)
		return (0);
	num[len] = '\0';
	while (n != 0)
	{
		num[len - 1] = n % 10 + 48;
		n = n / 10;
		len--;
	}
	return (num);
}

int	ft_putnbr_base(unsigned long n, char *base)
{
	unsigned long	base_len;
	unsigned long	num;
	int				l;

	l = 1;
	num = n;
	base_len = ft_strlen(base);
	if (num == 0)
	{
		ft_putchar_fd('0', 1);
		return (l);
	}
	if (num >= base_len)
	{
		l += ft_putnbr_base(num / base_len, base);
		ft_putchar_fd(base[num % base_len], 1);
	}
	else if (num < base_len)
		ft_putchar_fd(base[num], 1);
	return (l);
}

int	case_p(unsigned long shape)
{
	int	i;

	i = 0;
	i += write(1, "0x", 2);
	i += ft_putnbr_base(shape, "0123456789abcdef");
	return (i);
}

int	case_u(unsigned int shape)
{
	int			char_count;
	char		*chr_number;
	int			i;

	i = 0;
	char_count = 0;
	if (shape == 0)
		char_count += write(1, "0", 1);
	else
	{
		chr_number = ft_uitoa(shape);
		while (chr_number[i] != '\0')
			char_count += write(1, &chr_number[i++], 1);
		free (chr_number);
	}
	return (char_count);
}
