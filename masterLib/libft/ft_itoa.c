/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 17:03:04 by glevin            #+#    #+#             */
/*   Updated: 2024/05/26 16:38:12 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Allocates (with malloc(3)) and returns a string
representing the integer received as an argument.
Negative numbers must be handled.
*/

#include "libft.h"

static int	dignum(int n)
{
	int	cnt;
	int	temp;

	if (n == 0)
		return (1);
	cnt = 0;
	temp = n;
	while (temp != 0)
	{
		cnt++;
		temp /= 10;
	}
	return (cnt);
}

char	*ft_itoa(int n)
{
	int			digits;
	char		*res;
	long int	num;

	digits = dignum(n);
	num = n;
	if (num < 0)
	{
		digits++;
		num = -num;
	}
	res = (char *)malloc((digits + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	res[digits] = '\0';
	while (digits > 0)
	{
		res[--digits] = num % 10 + '0';
		num /= 10;
	}
	if (n < 0)
		res[0] = '-';
	return (res);
}
