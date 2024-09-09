/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 19:43:06 by glevin            #+#    #+#             */
/*   Updated: 2024/06/04 19:21:33 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Outputs the character ’c’ to the given file
descriptor.
*/

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}
