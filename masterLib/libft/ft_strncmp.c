/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:20:40 by glevin            #+#    #+#             */
/*   Updated: 2024/05/26 16:37:08 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Compares up to num characters of the C string str1 to those of the C string
str2.
This function starts comparing the first character of each string.
If they are equal to each other,
	it continues with the following pairs until the characters differ,
	until a terminating null-character is reached,
	or until num characters match in both strings, whichever happens first.
*/

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t num)
{
	size_t	i;

	if (num == 0)
		return (0);
	i = 0;
	while (i < num - 1 && str1[i] && str2[i])
	{
		if (str1[i] != str2[i])
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		i++;
	}
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}
