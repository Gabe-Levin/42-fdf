/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:32:18 by glevin            #+#    #+#             */
/*   Updated: 2024/06/06 16:06:16 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_putchar(char c);
int	ft_putdec(double n);
int	ft_puthex(unsigned int dec, int is_upper);
int	ft_putnbr(int n);
int	ft_putptr(void *p);
int	ft_putstr(char *s);
int	ft_putnbr_unsigned(unsigned int n);

#endif
