/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohulik <ohulik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 21:13:22 by ohulik            #+#    #+#             */
/*   Updated: 2022/01/23 21:13:24 by ohulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
*	LIBRARY
*	#include <ctype.h>
*	DESCRIPTION
*	The isdigit() function tests for a decimal digit character.
*	PARAMETERS
*	#1. The character to test.
*	RETURN VALUES
*	The isdigit() function returns zero if the character tests false and 
*	returns non-zero if the character tests true.
*/

#include "libft.h"

int	ft_isdigit(int c)
{
	if ((c < '0') || (c > '9'))
		return (0);
	return (1);
}
