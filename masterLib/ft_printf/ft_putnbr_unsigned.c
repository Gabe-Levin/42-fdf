/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:36:40 by glevin            #+#    #+#             */
/*   Updated: 2024/06/06 15:35:31 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_unsigned(unsigned int n)
{
	int		cnt;

	cnt = 0;
	if (n >= 10)
		cnt += ft_putnbr(n / 10);
	cnt += ft_putchar((n % 10) + '0');
	return (cnt);
}
