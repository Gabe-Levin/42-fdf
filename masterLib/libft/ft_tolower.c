/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:43:06 by glevin            #+#    #+#             */
/*   Updated: 2024/05/19 14:45:11 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
If the arguments passed to the tolower() function is other than an
uppercase alphabet,it returns the same character that is passed to the function.
*/
#include "libft.h"

int	ft_tolower(int arg)
{
	if (arg >= 65 && arg <= 90)
	{
		return (arg + 32);
	}
	return (arg);
}
