/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:52:25 by glevin            #+#    #+#             */
/*   Updated: 2024/05/26 16:37:45 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The C library function void *memchr(const void *str, int c,
	size_t n) searches for the first occurrence of the character c
	(an unsigned char) in the first n bytes of the string pointed to,
	by the argument str.
*/

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((const unsigned char *)str)[i] == (unsigned char)c)
		{
			return ((void *)(str + i));
		}
		i++;
	}
	return (NULL);
}
