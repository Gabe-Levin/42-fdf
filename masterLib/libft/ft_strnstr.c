/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 12:37:17 by glevin            #+#    #+#             */
/*   Updated: 2024/05/23 15:30:34 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The	strnstr(void) function locates the first	occurrence of the  null-termi-
		nated  string little in the string big, where not more than len charac-
		ters are	searched.  Characters that appear after	a `\0'	character  are
		not  searched.
*/

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	haystack_size;
	size_t	needle_size;
	size_t	i;

	i = 0;
	haystack_size = ft_strlen(haystack);
	needle_size = ft_strlen(needle);
	if (needle_size == 0)
		return ((char *)haystack);
	if (haystack_size == 0 || len == 0)
		return (NULL);
	while ((needle_size + i) <= len && haystack[i] != '\0')
	{
		if (haystack[i] == needle[0] && ft_strncmp(haystack + i, needle,
				needle_size) == 0)
			return ((char *)haystack + i);
		i++;
	}
	return (NULL);
}
