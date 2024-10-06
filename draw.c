/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 01:15:40 by glevin            #+#    #+#             */
/*   Updated: 2024/10/06 21:03:04 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/main.h"

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

void	draw_text(t_mlxData *mlxData)
{
	mlx_string_put(mlxData->mlx, mlxData->win, 10, 20, 0xFFFFFF,
		"Translate image: Arrow keys or wasd");
	mlx_string_put(mlxData->mlx, mlxData->win, 10, 40, 0xFFFFFF,
		"Rotate image: Q, E");
	mlx_string_put(mlxData->mlx, mlxData->win, 10, 60, 0xFFFFFF,
		"Adjust zoom:+,-");
}

void	redraw(t_mlxData *mlxData, t_pointData *pData, t_mapData *mapData)
{
	mlx_clear_window(mlxData->mlx, mlxData->win);
	if (mlxData->img)
		mlx_destroy_image(mlxData->mlx, mlxData->img);
	mlxData->img = mlx_new_image(mlxData->mlx, mlxData->win_width,
			mlxData->win_height);
	rotate_points(pData, mapData);
	printf("pData[0].rx: %d\npData[0].ry: %d\npData[0].rz: %d\n", pData->rx,
		pData->ry, pData->rz);
	printf("pData[0].dx: %d\npData[0].dy: %d\n", pData->dx,
		pData->dy);
	project_iso(pData, mapData);
	draw_points(pData, mlxData, mapData);
	draw_lines(pData, mlxData, mapData);
	printf("mapData->x_center: %d\n", mapData->x_center);
	printf("mapData->y_center: %d\n", mapData->y_center);
	mlx_put_image_to_window(mlxData->mlx, mlxData->win, mlxData->img, 0, 0);
	draw_text(mlxData);
}
