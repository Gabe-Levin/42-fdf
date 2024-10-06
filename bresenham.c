/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 20:18:23 by glevin            #+#    #+#             */
/*   Updated: 2024/10/06 20:34:07 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/main.h"

float	get_ratio(int x, int y, t_pointData *p1, t_pointData *p2)
{
	float	dist_total;
	float	dist_current;

	dist_total = sqrt((p2->dx - p1->dx) * (p2->dx - p1->dx) + (p2->dy - p1->dy)
			* (p2->dy - p1->dy));
	dist_current = sqrt((x - p1->dx) * (x - p1->dx) + (y - p1->dy) * (y
				- p1->dy));
	return (dist_current / dist_total);
}

void	bresenham(t_mlxData *img, t_pointData *p1, t_pointData *p2)
{
	int		x;
	int		y;
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		err;
	int		e2;
	int		color;
	float	ratio;

	x = p1->dx;
	y = p1->dy;
	dx = p2->dx - x;
	dy = p2->dy - y;
	// Step Directions
	if (dx > 0)
		sx = 1;
	else
		sx = -1;
	if (dy > 0)
		sy = 1;
	else
		sy = -1;
	if (dx < 0)
		dx = -dx;
	if (dy < 0)
		dy = -dy;
	// Error term initialization
	if (dx > dy)
		err = dx / 2;
	else
		err = -dy / 2;
	// Calc ratio
	while (x != p2->dx || y != p2->dy)
	{
		ratio = get_ratio(x, y, p1, p2);
		color = get_color(p1, p2, ratio);
		put_pixel_to_image(img, x, y, color);
		e2 = 2 * err;
		if (e2 > -dx)
		{
			err -= dy;
			x += sx;
		}
		if (e2 < dy)
		{
			err += dx;
			y += sy;
		}
	}
}
