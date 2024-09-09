/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 11:54:45 by glevin            #+#    #+#             */
/*   Updated: 2024/05/19 14:34:48 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Those characters that occupies printing space are known
as printable characters.

Printable characters are just the opposite of control
characters which can be checked using	iscntrl(void).
*/

#include "libft.h"

int	ft_isprint(int arg)
{
	if (arg >= 32 && arg <= 126)
	{
		return (1);
	}
	return (0);
}
