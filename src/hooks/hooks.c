/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 23:18:44 by glevin            #+#    #+#             */
/*   Updated: 2024/10/18 18:32:06 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/main.h"

void	translation_hooks(int keycode, t_hook_vars *hook_vars)
{
	if (keycode == KEY_UP || keycode == 119)
		hook_vars->m->y_offset -= 5;
	if (keycode == KEY_DOWN || keycode == 115)
		hook_vars->m->y_offset += 5;
	if (keycode == KEY_LEFT || keycode == 97)
		hook_vars->m->x_offset -= 5;
	if (keycode == KEY_RIGHT || keycode == 100)
		hook_vars->m->x_offset += 5;
}

void	rotation_hooks(int keycode, t_hook_vars *hook_vars)
{
	if (keycode == KEY_O)
		hook_vars->m->x_angle += 0.05;
	if (keycode == KEY_P)
		hook_vars->m->x_angle -= 0.05;
	if (keycode == KEY_K)
		hook_vars->m->y_angle += 0.05;
	if (keycode == KEY_L)
		hook_vars->m->y_angle -= 0.05;
	if (keycode == KEY_N)
		hook_vars->m->z_angle += 0.05;
	if (keycode == KEY_M)
		hook_vars->m->z_angle -= 0.05;
}

void	extrusion_hooks(int keycode, t_hook_vars *hook_vars)
{
	if (keycode == KEY_Z)
		hook_vars->m->extrusion_factor += 1;
	if (keycode == KEY_X)
		hook_vars->m->extrusion_factor -= 1;
}

void	color_hooks(int keycode, t_hook_vars *hook_vars)
{
	if (keycode == KEY_1)
		hook_vars->m->season = 0;
	if (keycode == KEY_2)
		hook_vars->m->season = 1;
	if (keycode == KEY_3)
		hook_vars->m->season = 2;
}

int	key_hooks(int keycode, t_hook_vars *hook_vars)
{
	if (keycode == KEY_ESC)
	{
		close_window(hook_vars);
	}
	translation_hooks(keycode, hook_vars);
	rotation_hooks(keycode, hook_vars);
	extrusion_hooks(keycode, hook_vars);
	color_hooks(keycode, hook_vars);
	if (keycode == KEY_4)
		hook_vars->m->projection = 0;
	if (keycode == KEY_5)
		hook_vars->m->projection = 1;
	if (keycode == 61 || keycode == 65451)
		hook_vars->m->zoom_lvl++;
	if (keycode == 45 || keycode == 65453)
		if (hook_vars->m->zoom_lvl != 1)
			hook_vars->m->zoom_lvl--;
	redraw(hook_vars->mlx, hook_vars->p, hook_vars->m);
	return (0);
}
