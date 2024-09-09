/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:26:55 by glevin            #+#    #+#             */
/*   Updated: 2024/05/23 13:11:01 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The C library function void *memmove(void *str1, const void *str2,
	size_t n) copies n characters from str2 to str1,
	but for overlapping memory blocks,
	memmove() is a safer approach than memcpy().
*/

#include "libft.h"

void	*ft_memmove(void *target, const void *source, size_t size)
{
	unsigned char	*t;
	unsigned char	*s;

	if (!target && !source)
		return ((void *)source);
	else if (target < source)
		return (ft_memcpy(target, source, size));
	t = (unsigned char *)target;
	s = (unsigned char *)source;
	while (size--)
		t[size] = s[size];
	return (target);
}
