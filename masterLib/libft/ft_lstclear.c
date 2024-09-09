/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 15:25:02 by glevin            #+#    #+#             */
/*   Updated: 2024/05/26 15:40:30 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Deletes and frees the given node and every
successor of that node, using the function ’del’
and	free(3).
Finally, the pointer to the list must be set to
NULL.
*/

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*temp_next;

	current = *lst;
	while (current)
	{
		temp_next = current->next;
		ft_lstdelone(current, del);
		current = temp_next;
	}
	*lst = NULL;
}
