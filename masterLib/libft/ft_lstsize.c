/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:50:08 by glevin            #+#    #+#             */
/*   Updated: 2024/05/26 16:33:30 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Counts the number of nodes in a list.
*/

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	cnt;

	cnt = 1;
	if (!lst)
		return (0);
	while (lst->next)
	{
		lst = lst->next;
		cnt++;
	}
	return (cnt);
}
