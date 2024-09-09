/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:33:50 by glevin            #+#    #+#             */
/*   Updated: 2024/06/06 17:24:26 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_long(unsigned long n)
{
	char	*lower;
	int		cnt;

	cnt = 0;
	lower = "0123456789abcdef";
	if (n == 0)
		return (ft_putchar('0'));
	if (n >= 16)
		cnt += ft_puthex_long(n / 16);
	cnt += ft_putchar(lower[n % 16]);
	return (cnt);
}

int	ft_putptr(void *p)
{
	unsigned long	dec;
	int				cnt;

	cnt = 0;
	dec = (unsigned long)p;
	if (dec == 0)
		return (ft_putstr("(nil)"));
	cnt += ft_putstr("0x");
	cnt += ft_puthex_long(dec);
	return (cnt);
}
