/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 11:33:58 by glevin            #+#    #+#             */
/*   Updated: 2024/05/19 14:27:43 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Returns 1 if argument is an alphanumeric character.
Returns 0 if argument is neither an alphabet nor a digit.
*/

#include "libft.h"

int	ft_isalnum(char c)
{
	if ((c >= 48 && c <= 57) || (c >= 65 && c <= 90) || (c >= 97 && c <= 122))
	{
		return (1);
	}
	return (0);
}
