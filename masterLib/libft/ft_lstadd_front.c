/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:42:16 by glevin            #+#    #+#             */
/*   Updated: 2024/05/24 16:48:32 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Adds the node ’new’ at the beginning of the list
*/

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
