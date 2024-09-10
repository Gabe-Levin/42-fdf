/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbageCollector.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 01:46:12 by glevin            #+#    #+#             */
/*   Updated: 2024/09/10 02:04:22 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "garbageCollector.h"

// static t_garbageNode *gc_head = NULL;

void *gc_malloc(size_t size)
{
    void *ptr = malloc(size);
    if(ptr)
    {
        t_garbageNode *new_node = malloc(sizeof(t_garbageNode));
        if (new_node)
        {
            new_node->ptr = ptr;
            new_node->next = gc_head;
            gc_head = new_node;
        }
        else
        {
            free(ptr);
            return NULL;
        }
    }
    return ptr;
}

void gc_free_all(void)
{
    t_garbageNode *current = gc_head;
    t_garbageNode *next;
    
    while (current)
    {
        next = current->next;
        free(current->ptr);
        free(current);
        current = next;
    }
    gc_head = NULL;
}