/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseInput.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 00:08:45 by glevin            #+#    #+#             */
/*   Updated: 2024/09/15 00:45:02 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

void	update_point(char *s, t_parse_vars vars, t_pointData *pData,
		t_mapData *mapData)
{
	pData[vars.pid].x = vars.col * mapData->zoom_lvl;
	pData[vars.pid].y = vars.row * mapData->zoom_lvl;
	pData[vars.pid].z = ft_atoi(s);
	pData[vars.pid].dx = (pData[vars.pid].x * cos(mapData->angle)
		- pData[vars.pid].y * cos(mapData->angle))+mapData->x_offset ;
	pData[vars.pid].dy = (pData[vars.pid].x * sin(mapData->angle)
		+ pData[vars.pid].y * sin(mapData->angle) - pData[vars.pid].z)+mapData->y_offset;
	// printf("vars.PID: %d\n", vars.pid);
	// printf("x: %d \ny: %d\nz:%d\n", pData[vars.pid].x, pData[vars.pid].y,
	// 	pData[vars.pid].z);
	// printf("dx: %d \ndy: %d\n", pData[vars.pid].dx, pData[vars.pid].dy);
	// printf("angle: %f \n", mapData->angle);
	// printf("----------\n");
}

void	update_all_points(t_pointData *pData, t_mapData *mapData)
{
	int	i;

	i = 0;
	while (i < mapData->vertices)
	{
		// printf("BEFORE: \n x: %i\n y: %i\n dx: %i\n dy: %i\n --------\n",
		// 	pData[i].x, pData[i].y, pData[i].dx, pData[i].dy);
		pData[i].dx = (pData[i].x * cos(mapData->angle) - pData[i].y
				* cos(mapData->angle)) + mapData->x_offset;
		pData[i].dy = (pData[i].x * sin(mapData->angle) + pData[i].y
				* sin(mapData->angle) - pData[i].z) + mapData->y_offset;
		// printf("AFTER: \n x: %i\n y: %i\ndx: %i\n dy: %i\n--------\n",
		// 	pData[i].x, pData[i].y, pData[i].dx, pData[i].dy);
		i++;
	}
	return ;
}

void	read_input(const char *filename, t_pointData *pData, t_mapData *mapData)
{
	int				fd;
	char			*l;
	char			**str;
	t_parse_vars	vars;

	vars.pid = 0;
	vars.row = 0;
	fd = open(filename, O_RDONLY);
	l = get_next_line(fd);
	while (l != NULL)
	{
		str = ft_split(l, ' ');
		vars.col = 0;
		while (str[vars.col])
		{
			update_point(str[vars.col], vars, pData, mapData);
			vars.col++;
			vars.pid++;
		}
		l = get_next_line(fd);
		vars.row++;
	}
	close(fd);
}

void	get_map_data(t_mapData **mapData, const char *filename)
{
	int		i;
	int		fd;
	char	*l;

	fd = open(filename, O_RDONLY);
	l = get_next_line(fd);
	while (l != NULL)
	{
		i = 0;
		while (l[i])
		{
			if (l[i] != ' ' && l[i] != '\n')
			{
				(*mapData)->vertices++;
				if (l[i + 1] && (l[i + 1] != ' ' || l[i + 1] != '\n'))
					i++;
			}
			if (l[i] == '\n')
				(*mapData)->rows++;
			i++;
		}
		l = get_next_line(fd);
	}
	(*mapData)->columns = (*mapData)->vertices / (*mapData)->rows;
	close(fd);
}

t_pointData	*init_points(const char *filename, t_mapData *mapData)
{
	t_pointData	*pData;

	pData = (t_pointData *)malloc(sizeof(t_pointData) * mapData->vertices);
	if (!pData)
	{
		return (NULL);
	}
	ft_memset(pData, 0, sizeof(t_pointData));
	read_input(filename, pData, mapData);
	return (pData);
}
