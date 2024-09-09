/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:11:38 by glevin            #+#    #+#             */
/*   Updated: 2024/05/26 16:37:25 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The function strdup() is used to duplicate a string. It returns a pointer to
null-terminated byte string.
*/

#include "libft.h"

char	*ft_strdup(const char *string)
{
	char	*str2;
	size_t	string_len;

	string_len = ft_strlen(string) + 1;
	str2 = malloc(string_len * sizeof(char));
	if (str2 == NULL)
		return (NULL);
	return ((char *)ft_memcpy(str2, string, string_len));
}
