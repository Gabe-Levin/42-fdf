/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:34:20 by glevin            #+#    #+#             */
/*   Updated: 2024/06/06 16:41:57 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int dec, int is_upper)
{
	int	rem;
	int	stack[32];
	int	top;
	int	cnt;

	cnt = 0;
	top = -1;
	if (dec == 0)
		return (ft_putnbr(0));
	while (dec != 0)
	{
		stack[++top] = dec % 16;
		dec = dec / 16;
	}
	while (top >= 0)
	{
		rem = stack[top--];
		if (rem < 10)
			cnt += ft_putnbr(rem);
		else if (is_upper == 1)
			cnt += ft_putchar(rem + 55);
		else
			cnt += ft_putchar(rem + 87);
	}
	return (cnt);
}
