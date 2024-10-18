/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 20:30:50 by glevin            #+#    #+#             */
/*   Updated: 2024/10/18 18:35:30 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

void	project_iso(t_pointData *p, t_mapData *m)
{
	int		i;
	int		x;
	int		y;
	int		z;
	float	rad;

	i = 0;
	rad = m->angle * (M_PI / 180.0);
	while (i < m->vertices)
	{
		x = p[i].rx;
		y = p[i].ry;
		z = p[i].rz;
		p[i].dx = ((x - y) * cos(rad)) + m->x_offset;
		p[i].dy = (-z + (x + y) * sin(rad)) + m->y_offset;
		i++;
	}
	return ;
}

void	project_parallel(t_pointData *p, t_mapData *m)
{
	int	i;

	i = 0;
	while (i < m->vertices)
	{
		p[i].dx = p[i].rx + m->x_offset;
		p[i].dy = p[i].ry + m->y_offset;
		i++;
	}
	return ;
}

void	project(t_pointData *p, t_mapData *m)
{
	if (m->projection == 0)
		project_iso(p, m);
	if (m->projection == 1)
		project_parallel(p, m);
}
