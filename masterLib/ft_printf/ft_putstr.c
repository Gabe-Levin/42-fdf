/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:37:38 by glevin            #+#    #+#             */
/*   Updated: 2024/06/04 19:05:22 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	cnt;

	cnt = 0;
	if (s == NULL)
		return (ft_putstr("(null)"));
	else
	{
		while (*s)
		{
			write(1, s, 1);
			s++;
			cnt++;
		}
	}
	return (cnt);
}
