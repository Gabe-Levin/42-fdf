/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 10:44:43 by glevin            #+#    #+#             */
/*   Updated: 2024/05/19 17:46:58 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
int			isalpha(int c);

In C programming,
	isalpha() function checks whether a character is an alphabet 
	(a to z and A-Z) or not.

If a character passed to isalpha() is an alphabet,
	it returns a non-zero integer, if not it returns 0.

Function	isalpha(void) takes a single argument in the form of 
an integer and returns an integer value.

Even though, isalpha() takes integer as an argument,
	character is passed to isalpha() function.

Internally,
	the character is converted into the integer value corresponding 
	to its ASCII value when passed.
*/

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
	{
		return (1);
	}
	return (0);
}
