/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohulik <ohulik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 02:07:10 by ohulik            #+#    #+#             */
/*   Updated: 2022/01/23 22:01:39 by ohulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	case_c(int shape)
{
	return (write(1, &shape, 1));
}

int	case_s(char *shape)
{
	int	i;

	i = 0;
	if (!shape)
		shape = "(null)";
	while (shape[i] != '\0')
		write(1, &shape[i++], 1);
	return (ft_strlen(shape));
}

int	case_di(int shape, int i)
{
	char	*ph;
	int		char_count;

	i = 0;
	ph = ft_itoa(shape);
	while (ph[i] != '\0')
		write(1, &ph[i++], 1);
	char_count = ft_strlen(ph);
	free(ph);
	return (char_count);
}

int	handle_conversions(va_list ap, const char *input_dup, int i)
{
	int			char_count;

	char_count = 0;
	if (input_dup[i] == 'c')
		char_count += case_c(va_arg(ap, int));
	else if (input_dup[i] == 's')
		char_count += case_s(va_arg(ap, char *));
	else if (input_dup[i] == 'p')
		char_count += case_p(va_arg(ap, unsigned long));
	else if (input_dup[i] == 'd' || input_dup[i] == 'i')
		char_count += case_di(va_arg(ap, int), i);
	else if (input_dup[i] == 'u')
		char_count += case_u(va_arg(ap, unsigned int));
	else if (input_dup[i] == 'x' || input_dup[i] == 'X')
		char_count += case_lxux(va_arg(ap, unsigned int), input_dup[i]);
	else
		char_count += write(1, "%", 1);
	return (char_count);
}

int	ft_printf(const char *input, ...)
{
	int			char_count;
	const char	*input_dup;
	va_list		ap;
	int			i;
	char		c;

	c = 0;
	i = 0;
	char_count = 0;
	input_dup = ft_strdup(input);
	va_start(ap, input);
	while (input_dup[i] != '\0')
	{
		if (input_dup[i] == '%')
			char_count += handle_conversions(ap, input_dup, ++i);
		else
		{
			c = input_dup[i];
			char_count += write (1, &c, 1);
		}
		i++;
	}
	free((char *)input_dup);
	va_end(ap);
	return (char_count);
}
