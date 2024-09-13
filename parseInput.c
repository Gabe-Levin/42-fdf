/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseInput.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 00:08:45 by glevin            #+#    #+#             */
/*   Updated: 2024/09/14 00:58:02 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int	parseStr(char *s, t_parse_vars vars, t_pointData *pData, t_mapData *mapData)
{
	int		i;
	int		row;
	int		column;
	double	angle;

	i = 0;
	row = 0;
	column = 0;
	angle = 0.5236; // 30 degrees in radians
	while (s[i])
	{
		if (s[i] != ' ' && s[i] != '\n')
		{
			// printf("%c\n", s[i]);
			// printf("x_offset: %d \ncolumn: %d\nzoom_lvl:%d\n",
			// 	mapData->x_offset, column, mapData->zoom_lvl);
			pData[vars.pid].x = mapData->x_offset + column * mapData->zoom_lvl;
			pData[vars.pid].y = mapData->y_offset + vars.row
				* mapData->zoom_lvl;
			if (s[i] != '0' && s[i + 1] != ' ' && s[i + 1] != '\0')
			{
				pData[vars.pid].z = ft_atoi(ft_substr(s, i, 2));
				i++;
			}
			else
				pData[vars.pid].z = s[i] - '0';
			pData[vars.pid].dx = pData[vars.pid].x * cos(angle)
				- pData[vars.pid].y * cos(angle);
			pData[vars.pid].dy = pData[vars.pid].x * sin(angle)
				+ pData[vars.pid].y * sin(angle) - pData[vars.pid].z;
			column++;
			// printf("vars.PID: %d\n", vars.pid);
			// printf("x: %d \ny: %d\nz:%d\n", pData[vars.pid].x,
			// 	pData[vars.pid].y, pData[vars.pid].z);
			// printf("dx: %d \ndy: %d\n", pData[vars.pid].dx, pData[vars.pid].dy);
			// printf("----------\n");
			vars.pid++;
		}
		else if (s[i] == '\n')
		{
			row++;
			column = 0;
		}
		i++;
	}
	return (vars.pid);
}

void	read_input(const char *filename, t_pointData *pData, t_mapData *mapData)
{
	int				fd;
	char			*l;
	t_parse_vars	vars;

	vars.pid = 0;
	vars.row = 0;
	fd = open(filename, O_RDONLY);
	l = get_next_line(fd);
	while (l != NULL)
	{
		vars.pid = parseStr(l, vars, pData, mapData);
		l = get_next_line(fd);
		vars.row++;
	}
	close(fd);
}

void	get_map_data(t_mapData *mapData, const char *filename)
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
				mapData->vertices++;
				if (l[i + 1] && (l[i + 1] != ' ' || l[i + 1] != '\n'))
					i++;
			}
			if (l[i] == '\n')
				mapData->rows++;
			i++;
		}
		l = get_next_line(fd);
	}
	mapData->columns = mapData->vertices / mapData->rows;
	close(fd);
}

t_pointData	*parse_input(const char *filename, t_mapData *mapData)
{
	t_pointData	*pData;

	pData = (t_pointData *)malloc(sizeof(t_pointData) * mapData->vertices);
	if (!pData)
	{
		return (NULL);
	}
	read_input(filename, pData, mapData);
	return (pData);
}
