/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_points.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 20:27:36 by glevin            #+#    #+#             */
/*   Updated: 2024/10/06 20:37:48 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/main.h"

t_pointData	*init_points(const char *filename, t_mapData *mapData)
{
	t_pointData	*pData;

	pData = (t_pointData *)malloc(sizeof(t_pointData) * mapData->vertices);
	if (!pData)
	{
		return (NULL);
	}
	ft_memset(pData, 0, sizeof(t_pointData) * mapData->vertices);
	read_input(filename, pData);
	rotate_points(pData, mapData);
	project_iso(pData, mapData);
	return (pData);
}

void	center_points(t_pointData *pData, t_mapData *mapData)
{
	int	default_zoom;
	int	min_delta;
	int	delta;

	min_delta = 1;
	delta = pData[mapData->vertices - 1].x - pData[0].x;
	if (abs(delta) < min_delta)
		default_zoom = 1;
	else
		default_zoom = (int)(400 / delta);
	if (default_zoom == 0)
		mapData->zoom_lvl = 1;
	else
		mapData->zoom_lvl = default_zoom;
	set_offsets(pData, mapData);
	printf("default_zoom, %d\n", default_zoom);
}
