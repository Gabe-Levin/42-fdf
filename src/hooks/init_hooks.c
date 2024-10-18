/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 11:46:56 by glevin            #+#    #+#             */
/*   Updated: 2024/10/18 18:35:39 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/main.h"

int	close_window(t_hook_vars *hook_vars)
{
	t_mlxData	*img;

	img = hook_vars->mlx;
	if (img->img)
	{
		mlx_destroy_image(img->mlx, img->img);
		img->img = NULL;
	}
	if (img->mlx && img->win)
	{
		mlx_destroy_window(img->mlx, img->win);
		img->win = NULL;
	}
	if (img->mlx)
	{
		mlx_destroy_display(img->mlx);
		free(img->mlx);
		img->mlx = NULL;
	}
	free(hook_vars->m);
	free(hook_vars->mlx);
	free(hook_vars->p);
	free(hook_vars);
	exit(0);
	return (0);
}

void	init_hooks(t_mlxData *img, t_mapData *m, t_pointData *p)
{
	t_hook_vars	*hook_vars;

	if (img == NULL || m == NULL || p == NULL)
	{
		return ;
	}
	hook_vars = (t_hook_vars *)malloc(sizeof(t_hook_vars));
	if (hook_vars == NULL)
	{
		return ;
	}
	hook_vars->mlx = img;
	hook_vars->m = m;
	hook_vars->p = p;
	mlx_hook(img->win, 17, 0, close_window, hook_vars);
	mlx_key_hook(img->win, key_hooks, hook_vars);
}
