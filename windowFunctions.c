/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windowFunctions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 23:18:44 by glevin            #+#    #+#             */
/*   Updated: 2024/09/13 16:54:38 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

#define KEY_LEFT  65361
#define KEY_RIGHT 65363

int	close_window(t_mlxData *img)
{
	mlx_destroy_window(img->mlx, img->win);
	mlx_destroy_display(img->mlx);
	free(img->mlx);
	return (0);
}

int	key_hook_close(int keycode, t_mlxData *img)
{
	if (keycode == 65307)
	{
		close_window(img);
		exit(0);
	}
	return (0);
}
int	key_hook_offset(int keycode, t_mapData *mapData)
{
	printf("zoom_lvl: %d\n", mapData->zoom_lvl);
	if (keycode == 65362)
	{
		return (0);
	}
	if (keycode == 65364)
	{
		return (0);
	}
	if (keycode == 65361)
	{
		return (0);
	}
	if (keycode == 65363)
	{
		return (0);
	}
	return (0);
}

void	init_window(t_mlxData *img, t_mapData *mapData)
{
	img->mlx = mlx_init();
	if (!img->mlx)
		return ;
	img->win = mlx_new_window(img->mlx, 800, 600, "FDF Test");
	if (!img->win)
	{
		free(img->mlx);
		return ;
	}
	img->img = mlx_new_image(img->mlx, 800, 600);
	mlx_hook(img->win, 17, 0, close_window, &img);
	mlx_key_hook(img->win, key_hook_close, &img);
	printf("x_offset: %d\n", mapData->x_offset);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	img->width = 800;
}
