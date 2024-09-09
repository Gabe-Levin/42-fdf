/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:59:44 by glevin            #+#    #+#             */
/*   Updated: 2024/06/06 15:35:45 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_convspec(const char **format, va_list args)
{
	int	cnt;

	cnt = 0;
	if (**format == 'c')
		cnt += ft_putchar((char)va_arg(args, int));
	else if (**format == 's')
		cnt += ft_putstr(va_arg(args, char *));
	else if (**format == 'd')
		cnt += ft_putnbr(va_arg(args, int));
	else if (**format == 'i')
		cnt += ft_putnbr(va_arg(args, int));
	else if (**format == 'u')
		cnt += ft_putnbr_unsigned(va_arg(args, unsigned int));
	else if (**format == 'x')
		cnt += ft_puthex(va_arg(args, unsigned int), 0);
	else if (**format == 'X')
		cnt += ft_puthex(va_arg(args, unsigned int), 1);
	else if (**format == 'p')
		cnt += ft_putptr(va_arg(args, void *));
	else if (**format == '%')
		cnt += ft_putchar('%');
	return (cnt);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		cnt;

	cnt = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			cnt += handle_convspec(&format, args);
		}
		else
			cnt += ft_putchar(*format);
		format++;
	}
	va_end(args);
	return (cnt);
}
