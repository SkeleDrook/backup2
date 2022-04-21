/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohulik <ohulik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 21:13:44 by ohulik            #+#    #+#             */
/*   Updated: 2022/01/23 21:13:46 by ohulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
*	DESCRIPTION
*	Adds the element ’new’ at the beginning of the list.
*	PARAMETERS
*	#1. The address of a pointer to the first link of a list.
*	#2. The address of a pointer to the element to be added to the list.
*	RETURN VALUES
*	-
*/

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new)
	{	
		if (!lst)
			*lst = new;
		new->next = *lst;
		*lst = new;
	}
}
