/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:36:40 by glevin            #+#    #+#             */
/*   Updated: 2024/06/06 15:31:47 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int		cnt;

	cnt = 0;
	if (n == -2147483648)
	{
		cnt += ft_putstr("-2147483648");
		return (cnt);
	}
	if (n < 0)
	{
		cnt += ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
		cnt += ft_putnbr(n / 10);
	cnt += ft_putchar((n % 10) + '0');
	return (cnt);
}
