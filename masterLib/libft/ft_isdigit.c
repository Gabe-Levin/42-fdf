/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 11:20:56 by glevin            #+#    #+#             */
/*   Updated: 2024/05/19 17:52:11 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Function	isdigit(void) takes a single argument in the form of
an integer and returns the value of type int.

Even though, isdigit() takes integer as an argument,
	character is passed to the function. Internally,
	the character is converted to its ASCII value for the check.
*/

#include "libft.h"

int	ft_isdigit(int arg)
{
	return (arg >= '0' && arg <= '9');
}
