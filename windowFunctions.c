/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windowFunctions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 23:18:44 by glevin            #+#    #+#             */
/*   Updated: 2024/10/06 20:34:07 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/main.h"

#define KEY_ESC 65307
#define KEY_UP 65362
#define KEY_DOWN 65364
#define KEY_LEFT 65361
#define KEY_RIGHT 65363
#define KEY_E 101
#define KEY_Q 113
#define KEY_Z 122
#define KEY_X 120
#define KEY_O 111
#define KEY_P 112
#define KEY_K 107
#define KEY_L 108
#define KEY_N 110
#define KEY_M 109

int	close_window(t_mlxData *img)
{
	mlx_destroy_window(img->mlx, img->win);
	mlx_destroy_display(img->mlx);
	free(img->mlx);
	return (0);
}

int	key_hooks(int keycode, t_hook_vars *hook_vars)
{
	printf("Keycode: %d\n", keycode);
	fflush(stdout);
	if (keycode == KEY_ESC)
	{
		close_window(hook_vars->mlxData->img);
		exit(0);
	}
	if (keycode == KEY_UP || keycode == 119)
		hook_vars->mapData->y_offset -= 5;
	if (keycode == KEY_DOWN || keycode == 115)
		hook_vars->mapData->y_offset += 5;
	if (keycode == KEY_LEFT || keycode == 97)
		hook_vars->mapData->x_offset -= 5;
	if (keycode == KEY_RIGHT || keycode == 100)
		hook_vars->mapData->x_offset += 5;
	if (keycode == KEY_E)
		hook_vars->mapData->angle += 5;
	if (keycode == KEY_Q)
		hook_vars->mapData->angle -= 5;
	if (keycode == KEY_Z)
		hook_vars->mapData->extrusion_factor += 5;
	if (keycode == KEY_X)
		hook_vars->mapData->extrusion_factor -= 5;
	if (keycode == KEY_O)
		hook_vars->mapData->x_angle += 0.05;
	if (keycode == KEY_P)
		hook_vars->mapData->x_angle -= 0.05;
	if (keycode == KEY_K)
		hook_vars->mapData->y_angle += 0.05;
	if (keycode == KEY_L)
		hook_vars->mapData->y_angle -= 0.05;
	if (keycode == KEY_N)
		hook_vars->mapData->z_angle += 0.05;
	if (keycode == KEY_M)
		hook_vars->mapData->z_angle -= 0.05;
	if (keycode == 61 || keycode == 65451)
		hook_vars->mapData->zoom_lvl++;
	if (keycode == 45 || keycode == 65453)
		if (hook_vars->mapData->zoom_lvl != 1)
			hook_vars->mapData->zoom_lvl--;
	redraw(hook_vars->mlxData, hook_vars->pData, hook_vars->mapData);
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
	img->win_height = WINDOW_HEIGHT;
	img->win_width = WINDOW_WIDTH;
	img->win = mlx_new_window(img->mlx, img->win_width, img->win_height,
			"FDF ");
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
