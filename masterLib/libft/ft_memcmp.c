/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 18:06:46 by glevin            #+#    #+#             */
/*   Updated: 2024/05/26 16:37:43 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The C library function int memcmp(const void *str1, const void *str2,
	size_t n)) compares the first n bytes of memory area str1 and memory area str2.
*/

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t				i;
	const unsigned char	*str1_str;
	const unsigned char	*str2_str;

	str1_str = (const unsigned char *)str1;
	str2_str = (const unsigned char *)str2;
	if (n == 0)
		return (0);
	i = 0;
	while (i < n - 1)
	{
		if (str1_str[i] != str2_str[i])
		{
			return (str1_str[i] - str2_str[i]);
		}
		i++;
	}
	return (str1_str[i] - str2_str[i]);
}
