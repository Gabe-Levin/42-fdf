/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 01:15:40 by glevin            #+#    #+#             */
/*   Updated: 2024/10/18 18:42:11 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

void	put_pixel_to_image(t_mlxData *img, int x, int y, int color)
{
	int	pixel_index;

	if (x < 0 || y < 0 || x >= img->win_width || y >= img->win_height)
		return ;
	pixel_index = (y * img->line_length + x * (img->bits_per_pixel / 8));
	img->addr[pixel_index] = color & 0xFF;
	img->addr[pixel_index + 1] = (color >> 8) & 0xFF;
	img->addr[pixel_index + 2] = (color >> 16) & 0xFF;
	img->addr[pixel_index + 3] = 0xFF;
}

void	draw_points(t_pointData *p, t_mlxData *img, t_mapData *m)
{
	int	i;

	i = 0;
	while (i < m->vertices)
	{
		if (!p[i].color_given)
			set_point_color(&p[i], m);
		put_pixel_to_image(img, p[i].dx, p[i].dy, p[i].color);
		i++;
	}
}

void	draw_lines(t_pointData *p, t_mlxData *img, t_mapData *m)
{
	int	i;

	i = 0;
	while (i < m->vertices)
	{
		if ((i + 1) % m->columns || i == 0)
			bresenham(img, &p[i], &p[i + 1]);
		if (i < (m->vertices - m->columns))
		{
			bresenham(img, &p[i], &p[i + m->columns]);
		}
		i++;
	}
}

void	draw_text(t_mlxData *mlx)
{
	mlx_string_put(mlx->mlx, mlx->win, 10, 20, 0xFFFFFF,
		"Translate image: Arrow keys or wasd");
	mlx_string_put(mlx->mlx, mlx->win, 10, 40, 0xFFFFFF, "Rotate image: Q, E");
	mlx_string_put(mlx->mlx, mlx->win, 10, 60, 0xFFFFFF, "Adjust zoom:+,-");
	mlx_string_put(mlx->mlx, mlx->win, 10, 80, 0xFFFFFF, "X-Rotation: O, P");
	mlx_string_put(mlx->mlx, mlx->win, 10, 100, 0xFFFFFF, "Y-Rotation: K, L");
	mlx_string_put(mlx->mlx, mlx->win, 10, 120, 0xFFFFFF, "Z-Rotation: N, M");
	mlx_string_put(mlx->mlx, mlx->win, 10, 140, 0xFFFFFF, "Colors: 1, 2, 3");
	mlx_string_put(mlx->mlx, mlx->win, 10, 160, 0xFFFFFF, "Isometric: 4");
	mlx_string_put(mlx->mlx, mlx->win, 10, 180, 0xFFFFFF, "Parallel: 5");
	mlx_string_put(mlx->mlx, mlx->win, 10, 200, 0xFFFFFF, "Extrusion: Z, X");
}

void	redraw(t_mlxData *mlx, t_pointData *p, t_mapData *m)
{
	mlx_clear_window(mlx->mlx, mlx->win);
	if (mlx->img)
		mlx_destroy_image(mlx->mlx, mlx->img);
	mlx->img = mlx_new_image(mlx->mlx, mlx->win_width, mlx->win_height);
	rotate_points(p, m);
	project(p, m);
	draw_points(p, mlx, m);
	draw_lines(p, mlx, m);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	draw_text(mlx);
}
