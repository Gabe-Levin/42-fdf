/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 20:18:23 by glevin            #+#    #+#             */
/*   Updated: 2024/10/18 17:57:25 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

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

typedef struct s_bres
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
}			t_bres;

void	bresenham_loop(t_bres b, t_mlxData *img, t_pointData *p1,
		t_pointData *p2)
{
	while (b.x != p2->dx || b.y != p2->dy)
	{
		b.ratio = get_ratio(b.x, b.y, p1, p2);
		b.color = get_color(p1, p2, b.ratio);
		put_pixel_to_image(img, b.x, b.y, b.color);
		b.e2 = 2 * b.err;
		if (b.e2 > -b.dx)
		{
			b.err -= b.dy;
			b.x += b.sx;
		}
		if (b.e2 < b.dy)
		{
			b.err += b.dx;
			b.y += b.sy;
		}
	}
}

void	bresenham(t_mlxData *img, t_pointData *p1, t_pointData *p2)
{
	t_bres	b;

	b.x = p1->dx;
	b.y = p1->dy;
	b.dx = p2->dx - b.x;
	b.dy = p2->dy - b.y;
	if (b.dx > 0)
		b.sx = 1;
	else
		b.sx = -1;
	if (b.dy > 0)
		b.sy = 1;
	else
		b.sy = -1;
	if (b.dx < 0)
		b.dx = -b.dx;
	if (b.dy < 0)
		b.dy = -b.dy;
	if (b.dx > b.dy)
		b.err = b.dx / 2;
	else
		b.err = -b.dy / 2;
	bresenham_loop(b, img, p1, p2);
}
