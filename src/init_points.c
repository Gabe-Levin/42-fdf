/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_points.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 20:27:36 by glevin            #+#    #+#             */
/*   Updated: 2024/10/10 14:27:04 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

void	center_points(t_pointData *p, t_mapData *m)
{
	int			default_zoom;
	t_pointData	*mid_i;
	int			min_delta;
	int			delta;

	min_delta = 1;
	mid_i = &p[m->vertices / 2];
	mid_i = mid_i;
	delta = p[m->vertices - 1].x - p[0].x;
	if (abs(delta) < min_delta)
		default_zoom = 1;
	else
		default_zoom = (int)(400 / delta);
	if (default_zoom == 0)
		m->zoom_lvl = 1;
	else
		m->zoom_lvl = default_zoom;
	m->x_center = p[m->vertices / 2].x * m->zoom_lvl;
	m->y_center = p[m->vertices / 2].y * m->zoom_lvl;
	m->z_center = p[m->vertices / 2].z * m->extrusion_factor;
	m->x_offset = (WINDOW_WIDTH / 2) - (p[m->vertices / 2].rx * m->zoom_lvl);
	m->y_offset = WINDOW_HEIGHT / 4;
}
