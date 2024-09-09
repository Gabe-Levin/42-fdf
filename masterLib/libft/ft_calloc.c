/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 13:48:02 by glevin            #+#    #+#             */
/*   Updated: 2024/05/24 15:25:36 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The C library function void *calloc(size_t nitems,
	size_t size) allocates the requested memory and returns a pointer to it.
	The difference in malloc and calloc is that malloc does not set the memory
	to zero where as calloc sets allocated memory to zero.
*/

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*ptr;

	ptr = malloc(nitems * size);
	if (ptr == NULL)
		return (ptr);
	ft_bzero(ptr, nitems * size);
	return (ptr);
}
