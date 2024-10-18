/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 20:10:43 by glevin            #+#    #+#             */
/*   Updated: 2024/10/10 14:48:31 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

void	rotate_x(t_pointData *p, double angle)
{
	int	prev_ry;
	int	prev_rz;

	prev_ry = p->ry;
	prev_rz = p->rz;
	p->ry = prev_ry * cos(angle) - prev_rz * sin(angle);
	p->rz = prev_ry * sin(angle) + prev_rz * cos(angle);
}

void	rotate_y(t_pointData *p, double angle)
{
	int	prev_rx;
	int	prev_rz;

	prev_rx = p->rx;
	prev_rz = p->rz;
	p->rx = prev_rx * cos(angle) + prev_rz * sin(angle);
	p->rz = -prev_rx * sin(angle) + prev_rz * cos(angle);
}

void	rotate_z(t_pointData *p, double angle)
{
	int	prev_rx;
	int	prev_ry;

	prev_rx = p->rx;
	prev_ry = p->ry;
	p->rx = prev_rx * cos(angle) - prev_ry * sin(angle);
	p->ry = prev_rx * sin(angle) + prev_ry * cos(angle);
}

void	rotate_points(t_pointData *p, t_mapData *m)
{
	int	i;

	i = 0;
	while (i < m->vertices)
	{
		p[i].rx = p[i].x * m->zoom_lvl;
		p[i].ry = p[i].y * m->zoom_lvl;
		p[i].rz = p[i].z * m->extrusion_factor;
		p[i].rx -= m->x_center;
		p[i].ry -= m->y_center;
		p[i].rz -= m->z_center;
		rotate_x(&p[i], m->x_angle);
		rotate_y(&p[i], m->y_angle);
		rotate_z(&p[i], m->z_angle);
		p[i].rx += m->x_center;
		p[i].ry += m->y_center;
		p[i].rz += m->z_center;
		i++;
	}
}
