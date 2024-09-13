/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseInput.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 00:08:45 by glevin            #+#    #+#             */
/*   Updated: 2024/09/13 02:48:16 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

char	*readInput(const char *filename)
{
	char	*buffer;
	int		fd;
	int		byte_cnt;

	buffer = (char *)malloc(BUFFER_SIZE2);
	if (!buffer)
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		free(buffer);
		return (NULL);
	}
	byte_cnt = read(fd, buffer, BUFFER_SIZE2);
	if (byte_cnt == -1)
	{
		free(buffer);
		close(fd);
		return (NULL);
	}
	buffer[byte_cnt] = '\0';
	return (buffer);
}

t_pointData	*parseStr(char *s, t_pointData *pData, t_mapData *mapData)
{
	int		i;
	int		pid;
	int		row;
	int		column;
	double	angle;

	i = 0;
	pid = 0;
	row = 0;
	column = 0;
	angle = 0.5236; // 30 degrees in radians
	while (s[i])
	{
		printf("x_offset: %d\n", mapData->x_offset);
		printf("y_offset: %d\n", mapData->y_offset);
		if (s[i] != ' ' && s[i] != '\n')
		{
			pData[pid].x = mapData->x_offset + column * mapData->zoom_lvl;
			pData[pid].y = mapData->y_offset + row * mapData->zoom_lvl;
			if (s[i] != '0' && s[i + 1] != ' ' && s[i + 1] != '\0')
			{
				pData[pid].z = ft_atoi(ft_substr(s, i, 2));
				i++;
			}
			else
				pData[pid].z = s[i] - '0';
			pData[pid].dx = pData[pid].x * cos(angle) - pData[pid].y
				* cos(angle);
			pData[pid].dy = pData[pid].x * sin(angle) + pData[pid].y
				* sin(angle) - pData[pid].z;
			column++;
			// printf("PID: %d\n", pid);
			// printf("Column: %d \nrow: %d\nheight:%d\n", pData[pid].x,
			// 	pData[pid].y, pData[pid].z);
			// // printf("dx: %d \ndy: %d\n", pData[pid].dx, pData[pid].dy);
			// printf("----------\n");
			pid++;
		}
		else if (s[i] == '\n')
		{
			row++;
			column = 0;
		}
		i++;
	}
	return (pData);
}

void	getMapData(char *s, t_mapData *mapData)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != ' ' && s[i] != '\n')
		{
			mapData->vertices++;
			if (s[i + 1] && (s[i + 1] != ' ' || s[i + 1] != '\n'))
				i++;
		}
		if (s[i] == '\n')
			mapData->rows++;
		i++;
	}
	mapData->columns = mapData->vertices / mapData->rows;
}

t_pointData	*parseInput(const char *filename, t_mapData *mapData)
{
	t_pointData	*pData;
	char		*inputStr;

	inputStr = readInput(filename);
	getMapData(inputStr, mapData);
	pData = (t_pointData *)malloc(mapData->vertices * (sizeof(t_pointData)));
	if (!pData)
	{
		free(inputStr);
		return (NULL);
	}
	pData = parseStr(inputStr, pData, mapData);
	return (pData);
}
