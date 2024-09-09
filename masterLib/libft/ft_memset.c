/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:00:44 by glevin            #+#    #+#             */
/*   Updated: 2024/05/26 16:37:38 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The C library function void *memset(void *str, int c,
	size_t n) copies the character c (an unsigned char) to the
	first n characters of the string pointed to,
	by the argument str.
*/

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*s;
	size_t			i;

	s = str;
	i = 0;
	while (i < n)
	{
		s[i] = (unsigned char)c;
		i++;
	}
	return (str);
}
