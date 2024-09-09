/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:35:41 by glevin            #+#    #+#             */
/*   Updated: 2024/05/26 16:38:27 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The	bzero(void) function erases the data in the n bytes of the memory
		starting at the location pointed to by s, by writing zeros (bytes
		containing '\0') to that area.
*/

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}
