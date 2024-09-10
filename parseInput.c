/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseInput.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 00:08:45 by glevin            #+#    #+#             */
/*   Updated: 2024/09/10 03:22:23 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <main.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

#define MAX_ROWS 11
#define MAX_COLS 19

typedef struct s_pointData
{
	int		x;
	int		y;
	int		z;
	int		dx;
	int		dy;
}			t_pointData;

typedef struct s_mapData
{
	int		rows;
	int		columns;
	int		vertices;

}			t_mapData;

#include <stdio.h>
#include <stdlib.h>

char	*readInput(const char *filename)
{
	char	*buffer;
	int		fd;
	int		byte_cnt;

	buffer = (char *)malloc(BUFFER_SIZE);
	if (!buffer)
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		free(buffer);
		return (NULL);
	}
	byte_cnt = read(fd, buffer, BUFFER_SIZE);
	if (byte_cnt == -1)
	{
		free(buffer);
		close(fd);
		return (NULL);
	}
	buffer[byte_cnt] = '\0';
	return (buffer);
}

t_pointData	*parseStr(char *s, t_mapData *mapData)
{
	int			i;
	int			row;
	int			column;
	t_pointData	points[mapData->vertices];

	i = 0;
	row = 0;
	column = 0;
	printf("HERE");
	while (s[i])
	{
		if (s[i] == '0')
		{
			points[i].x = column;
			points[i].y = row;
			points[i].z = 0;
			column++;
			printf("column: %d \nrow: %d\nheight:%d\n", points[i].x,
				points[i].y, points[i].z);
			printf("----------\n");
		}
		else if (s[i] == '1')
		{
			points[i].x = column;
			points[i].y = row;
			points[i].z = 10;
			column++;
			i++;
			printf("column: %d \nrow: %d\nheight:%d\n", points[i].x,
				points[i].y, points[i].z);
			printf("----------\n");
		}
		else if (s[i] == '\n')
		{
			row++;
			column = 0;
			printf("%s", "\n");
		}
		i++;
	}
	// printf("%s", s);
	return (points);
}

void	getMapData(char *s, t_mapData *mapData)
{
	int	i;

	i = 0;
	mapData->vertices = 0;
	mapData->rows = 0;
	while (s[i])
	{
		// printf("%c", s[i]);
		if (s[i] == '0')
			mapData->vertices++;
		if (s[i] == '1')
		{
			mapData->vertices++;
			i++;
		}
		if (s[i] == '\n')
			mapData->rows++;
		i++;
	}
	mapData->columns = mapData->vertices / mapData->rows;
}

t_pointData	*parseInput(const char *filename)
{
	t_pointData	*pData;
	t_mapData	*mapData;
	char		*inputStr;
	int			rows;
	int			columns;
	int			vertices;

	inputStr = readInput(filename);
	getMapData(inputStr, mapData);
	// printf("row = %d, columns = %d, vertices = %d", mapData->rows,
	// 	mapData->columns, mapData->vertices);
	pData = parseStr(inputStr, mapData);
	return (pData);
}

int	main(void)
{
	parseInput("./maps/42.fdf");
	return (0);
}
