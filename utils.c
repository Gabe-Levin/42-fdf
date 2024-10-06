/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:34:54 by glevin            #+#    #+#             */
/*   Updated: 2024/10/06 20:56:52 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/main.h"

void	free_split_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	calc_center(t_pointData *pData, t_mapData *mapData)
{
	int		i;
	int	sum_x;
	int	sum_y;
	int	sum_z;

	sum_x = 0;
	sum_y = 0;
	sum_y = 0;
	for (i = 0; i < mapData->vertices; i++)
	{
		sum_x += pData[i].x * mapData->zoom_lvl;
		sum_y += pData[i].y * mapData->zoom_lvl;
		sum_z += pData[i].z;
		// printf("===> sum_z: %d\n", sum_z);
	}
	mapData->x_center = (int)(sum_x / mapData->vertices);
	mapData->y_center = (int)(sum_y / mapData->vertices);
	mapData->z_center = (int)(sum_z / mapData->vertices);
	// printf("-----------\n");
	// printf("sum_x: %d\n", sum_x);
	// printf("sum_y: %d\n", sum_y);
	// printf("sum_z: %d\n", sum_z);
	// printf("mapData->x_center: %d\n", mapData->x_center);
	// printf("mapData->y_center: %d\n", mapData->y_center);
	// printf("mapData->z_center: %d\n", mapData->z_center);
}

void	translate_to_origin(t_pointData *p, t_mapData *m)
{
	for (int i = 0; i < m->vertices; i++)
	{
		p[i].x -= m->x_center;
		p[i].y -= m->y_center;
		p[i].z -= m->z_center;
	}
}

void	translate_back(t_pointData *p, t_mapData *m)
{
	for (int i = 0; i < m->vertices; i++)
	{
		p[i].x += m->x_center;
		p[i].y += m->y_center;
		p[i].z += m->z_center;
	}
}

int	hex_to_int(const char *hex_str)
{
	int	result;
	int	value;

	result = 0;
	value = 0;
	if (hex_str[0] == '0' && (hex_str[1] == 'x' || hex_str[1] == 'X'))
		hex_str += 2;
	while (*hex_str)
	{
		if (ft_isdigit(*hex_str))
			value = *hex_str - '0';
		else if (*hex_str >= 'a' && *hex_str <= 'f')
			value = *hex_str - 'a' + 10;
		else if (*hex_str >= 'A' && *hex_str <= 'F')
			value = *hex_str - 'A' + 10;
		else
			break ;
		result = (result << 4) | value;
		hex_str++;
	}
	return (result);
}
