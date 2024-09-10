/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbageCollector.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 01:47:13 by glevin            #+#    #+#             */
/*   Updated: 2024/09/10 02:04:19 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GARBAGECOLLECTOR_H
# define GARGBAGECOLLECOTR_H
#include <stdlib.h>

typedef struct s_garbageNode
{
    void *ptr;
    struct s_garbageNode *next;
} t_garbageNode;

void *gc_malloc(size_t size);
void gc_free_all(void);

#endif