/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 01:08:27 by glevin            #+#    #+#             */
/*   Updated: 2024/10/18 18:34:12 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

int	get_point_color(int s, int level)
{
	int	l;
	int	season[4][6];

	l = 0;
	while (l < 3)
	{
		season[l][0] = MIDNIGHT_BLUE;
		season[l][5] = WHITE;
		l++;
	}
	season[0][1] = NICE_BLUE;
	season[0][2] = LAWN_GREEN;
	season[0][3] = GREEN;
	season[0][4] = BROWN;
	season[1][1] = CYAN;
	season[1][2] = NICE_BLUE;
	season[1][3] = RED;
	season[1][4] = CRIMSON;
	season[2][1] = LAWN_GREEN;
	season[2][2] = GREEN;
	season[2][3] = RED;
	season[2][4] = GOLD;
	return (season[s][level]);
}

void	set_point_color(t_pointData *p, t_mapData *m)
{
	int	level;

	level = 0;
	if (p->color_given == 1)
		return ;
	if (p->z < -50)
		level = 0;
	else if (p->z < 0)
		level = 1;
	else if (p->z < 0.3 * m->z_max)
		level = 2;
	else if (p->z < 0.6 * m->z_max)
		level = 3;
	else if (p->z < 0.9 * m->z_max)
		level = 4;
	else
		level = 5;
	p->color = get_point_color(m->season, level);
}

int	get_color(t_pointData *p1, t_pointData *p2, double ratio)
{
	int	red;
	int	green;
	int	blue;
	int	color;

	red = ((p1->color >> 16) & 0xFF) * (1 - ratio) + ((p2->color >> 16) & 0xFF)
		* ratio;
	green = ((p1->color >> 8) & 0xFF) * (1 - ratio) + ((p2->color >> 8) & 0xFF)
		* ratio;
	blue = ((p1->color & 0xFF) * (1 - ratio) + (p2->color & 0xFF) * ratio);
	color = (red << 16) | (green << 8) | blue;
	return (color);
}
