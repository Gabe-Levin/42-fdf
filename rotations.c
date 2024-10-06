/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 20:10:43 by glevin            #+#    #+#             */
/*   Updated: 2024/10/06 20:58:03 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/main.h"

void	rotate_x(t_pointData *p, double angle)
{
	p->rx = p->x;
	p->ry = p->y * cos(angle) - p->z * sin(angle);
	p->rz = p->y * sin(angle) + p->z * cos(angle);
}

void	rotate_y(t_pointData *p, double angle)
{
	p->rx = p->x * cos(angle) + p->z * sin(angle);
	p->ry = p->y;
	p->rz = -p->x * sin(angle) + p->z * cos(angle);
}

void	rotate_z(t_pointData *p, double angle)
{
	p->rx = p->x * cos(angle) - p->y * sin(angle);
	p->ry = p->x * sin(angle) + p->y * cos(angle);
	p->rz = p->z;
}

void	rotate_points(t_pointData *p, t_mapData *m)
{
	int	i;

	i = 0;
	calc_center(p, m);
	translate_to_origin(p, m);
	while (i < m->vertices)
	{
		rotate_x(&p[i], m->x_angle);
		rotate_y(&p[i], m->y_angle);
		rotate_z(&p[i], m->z_angle);
		i++;
	}
	translate_back(p, m);
}
