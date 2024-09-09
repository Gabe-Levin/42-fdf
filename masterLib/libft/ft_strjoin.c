/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 18:22:26 by glevin            #+#    #+#             */
/*   Updated: 2024/05/26 16:37:22 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Allocates (with malloc(3)) and returns a new
string, which is the result of the concatenation
of ’s1’ and ’s2’.
*/

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		i;
	size_t	s1_len;
	size_t	s2_len;

	i = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	s3 = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (s3 == NULL)
		return (NULL);
	s3 = ft_memcpy(s3, s1, s1_len);
	while (s2[i])
	{
		s3[s1_len + i] = s2[i];
		i++;
	}
	s3[s1_len + i] = '\0';
	return (s3);
}
