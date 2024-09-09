/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:47:26 by glevin            #+#    #+#             */
/*   Updated: 2024/05/24 14:32:43 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The C library function char *strchr(const char *str,
	int c) searches for the first occurrence of the character c
	(an unsigned char) in the string pointed to by the argument str.

*/

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != (unsigned char)c)
	{
		if (!str[i++])
			return (0);
	}
	return ((char *)(&str[i]));
}
