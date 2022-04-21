/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohulik <ohulik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 15:06:18 by ohulik            #+#    #+#             */
/*   Updated: 2022/01/23 20:14:05 by ohulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

int				ft_printf(const char *input, ...);
int				handle_conversions(va_list ap, const char *input_dup, int i);
int				case_c(int shape);
int				case_s(char *shape);
int				case_p(unsigned long shape);
int				case_di(int shape, int i);
int				case_u(unsigned int shape);
char			*ft_uitoa(unsigned int n);
int				case_lxux(unsigned int shape, int sign);
int				hex_len(unsigned int num);
int				ft_num_len(unsigned	int num);

#endif