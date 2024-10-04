/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 01:15:40 by glevin            #+#    #+#             */
/*   Updated: 2024/10/04 18:57:52 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	put_pixel_to_image(t_mlxData *img, int x, int y, int color)
{
	int	pixel_index;

	if (x < 0 || y < 0 || x >= img->win_width || y >= 600)
		return ;
	pixel_index = (y * img->line_length + x * (img->bits_per_pixel / 8));
	// Set the pixel color (assuming endian is handled elsewhere)
	img->addr[pixel_index] = color & 0xFF;             // Blue channel
	img->addr[pixel_index + 1] = (color >> 8) & 0xFF;  // Green channel
	img->addr[pixel_index + 2] = (color >> 16) & 0xFF; // Red channel
	img->addr[pixel_index + 3] = 0xFF;
}

void	draw_points(t_pointData *pData, t_mlxData *img, t_mapData *mapData)
{
	int	i;

	i = 0;
	while (i < mapData->vertices)
	{
		if (!pData[i].color_given)
			set_point_color(&pData[i], mapData);
		put_pixel_to_image(img, pData[i].dx, pData[i].dy, pData[i].color);
		i++;
	}
}

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

void	draw_lines(t_pointData *pData, t_mlxData *img, t_mapData *mapData)
{
	int	i;

	i = 0;
	while (i < mapData->vertices)
	{
		if ((i + 1) % mapData->columns || i == 0)
			bresenham(img, &pData[i], &pData[i + 1]);
		if (i < (mapData->vertices - mapData->columns))
		{
			bresenham(img, &pData[i], &pData[i + mapData->columns]);
		}
		i++;
	}
}
