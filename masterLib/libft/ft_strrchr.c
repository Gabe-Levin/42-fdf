/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:09:26 by glevin            #+#    #+#             */
/*   Updated: 2024/05/26 16:37:03 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Returns a pointer to the last occurrence of character in the C string str.

The terminating null-character is considered part of the C string. Therefore,
	it can also be located to retrieve a pointer to the end of a string.
*/

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (c == '\0')
		return ((char *)&str[i]);
	while (i >= 0)
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i--;
	}
	return (NULL);
}
