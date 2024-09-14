/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windowFunctions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 23:18:44 by glevin            #+#    #+#             */
/*   Updated: 2024/09/15 00:45:46 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

#define KEY_ESC 65307
#define KEY_UP 65362
#define KEY_DOWN 65364
#define KEY_LEFT 65361
#define KEY_RIGHT 65363

int	close_window(t_mlxData *img)
{
	mlx_destroy_window(img->mlx, img->win);
	mlx_destroy_display(img->mlx);
	free(img->mlx);
	return (0);
}

int	key_hooks(int keycode, t_hook_vars *hook_vars)
{
	if (keycode == KEY_ESC)
	{
		close_window(hook_vars->mlxData->img);
		exit(0);
	}

	if (keycode == KEY_UP)
	{
		// mlx_clear_window(hook_vars->mlxData->mlx, hook_vars->mlxData->win);
		hook_vars->mapData->y_offset++;
		redraw(hook_vars->mlxData, hook_vars->pData, hook_vars->mapData);
		return (0);
	}
	// if (keycode == KEY_DOWN)
	// {
	// 	return (0);
	// }
	// if (keycode == KEY_LEFT)
	// {
	// 	return (0);
	// }
	// if (keycode == KEY_RIGHT)
	// {
	// 	return (0);
	// }
	return (0);
}
void	init_hooks(t_mlxData *img, t_mapData *mapData, t_pointData *pData)
{
	t_hook_vars	*hook_vars;

	if (img == NULL || mapData == NULL || pData == NULL)
	{
		return ;
	}
	hook_vars = (t_hook_vars *)malloc(sizeof(t_hook_vars));
	if (hook_vars == NULL)
	{
		return ;
	}
	hook_vars->mlxData = img;
	hook_vars->mapData = mapData;
	hook_vars->pData = pData;
	mlx_hook(img->win, 17, 0, close_window, &img);
	mlx_key_hook(img->win, key_hooks, hook_vars);
}

t_mlxData	*init_image(void)
{
	t_mlxData	*img;

	img = (t_mlxData *)malloc(sizeof(t_mlxData));
	if (img == NULL)
		return (NULL);
	ft_memset(img, 0, sizeof(t_mlxData));
	img->mlx = mlx_init();
	if (!img->mlx)
		return (NULL);
	img->win_height = 600;
	img->win_width = 800;
	img->win = mlx_new_window(img->mlx, img->win_width, img->win_height,
			"FDF Test");
	if (!img->win)
	{
		free(img->mlx);
		return (NULL);
	}
	img->img = mlx_new_image(img->mlx, img->win_width, img->win_height);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	return (img);
}
