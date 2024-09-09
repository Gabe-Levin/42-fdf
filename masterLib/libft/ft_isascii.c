/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 11:44:08 by glevin            #+#    #+#             */
/*   Updated: 2024/05/19 18:03:26 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Bestimmt, ob ein angegebenes Zeichen ein ASCII-Zeichen ist.
*/

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
	{
		return (1);
	}
	return (0);
}
