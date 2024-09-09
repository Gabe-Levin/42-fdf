/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 18:51:46 by glevin            #+#    #+#             */
/*   Updated: 2024/05/24 14:33:37 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Allocates (with malloc(3)) and returns a copy of
’s1’ with the characters specified in ’set’ removed
from the beginning and the end of the string.
*/

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	size_t	s1_len;
	int		i;
	int		j;

	if (*s1 == '\0' || *set == '\0')
		return (ft_strdup(s1));
	i = 0;
	s1_len = ft_strlen(s1);
	j = s1_len;
	while (ft_strchr(set, s1[i]))
	{
		if (s1[i] == '\0')
			return (ft_strdup(""));
		i++;
	}
	while (ft_strchr(set, s1[j - 1]))
		j--;
	res = ft_substr(s1, i, j - i);
	return (res);
}
