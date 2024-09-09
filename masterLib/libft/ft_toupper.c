/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:39:00 by glevin            #+#    #+#             */
/*   Updated: 2024/05/19 14:45:16 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
If an argument passed to toupper() is

a lowercase character, the function returns its corresponding uppercase
character an uppercase character or a non-alphabetic character,
the function the character itself
*/

#include "libft.h"

int	ft_toupper(int ch)
{
	if (ch >= 97 && ch <= 122)
	{
		return (ch - ('a' - 'A'));
	}
	return (ch);
}
