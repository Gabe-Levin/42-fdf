/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 20:30:50 by glevin            #+#    #+#             */
/*   Updated: 2024/10/06 20:34:07 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/main.h"

void	project_iso(t_pointData *pData, t_mapData *mapData)
{
	int		i;
	int		x;
	int		y;
	int		z;
	float	rad;

	i = 0;
	rad = mapData->angle * (M_PI / 180.0);
	while (i < mapData->vertices)
	{
		x = pData[i].rx * mapData->zoom_lvl;
		y = pData[i].ry * mapData->zoom_lvl;
		z = pData[i].rz * mapData->extrusion_factor;
		pData[i].dx = (x - y) * cos(rad) + mapData->x_offset;
		pData[i].dy = -z + (x + y) * sin(rad) + mapData->y_offset;
		i++;
	}
	return ;
}
