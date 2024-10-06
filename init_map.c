/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 20:28:31 by glevin            #+#    #+#             */
/*   Updated: 2024/10/06 20:46:06 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/main.h"

void	set_offsets(t_pointData *pData, t_mapData *mapData)
{
	calc_center(pData, mapData);
	pData = pData;
	mapData->x_offset = (WINDOW_WIDTH / 2) + ((WINDOW_WIDTH / 2)
			- mapData->x_center);
	mapData->y_offset = (WINDOW_HEIGHT / 2) + ((WINDOW_HEIGHT / 2)
			- mapData->y_center - 200);
	printf("mapData->x_offset: %d\n", mapData->x_offset);
	printf("mapData->y_offset: %d\n", mapData->y_offset);
	printf("mapData->x_center: %d\n", mapData->x_center);
	printf("mapData->y_center: %d\n", mapData->y_center);
}

void	get_map_data(t_mapData **mapData, const char *filename)
{
	int		i;
	int		fd;
	char	*l;
	char	**str;

	fd = open(filename, O_RDONLY);
	l = get_next_line(fd);
	while (l != NULL)
	{
		i = 0;
		str = ft_split(l, ' ');
		while (str[i])
		{
			if (str[i][0] != '\n')
			{
				if (ft_atoi(str[i]) < (*mapData)->z_min)
					(*mapData)->z_min = ft_atoi(str[i]);
				if (ft_atoi(str[i]) > (*mapData)->z_max)
					(*mapData)->z_max = ft_atoi(str[i]);
				(*mapData)->vertices++;
			}
			i++;
		}
		(*mapData)->rows++;
		free_split_str(str);
		free(l);
		l = get_next_line(fd);
	}
	free(l);
	(*mapData)->columns = (*mapData)->vertices / (*mapData)->rows;
	close(fd);
}

t_mapData	*init_mapData(char *filename)
{
	t_mapData	*mapData;

	mapData = (t_mapData *)malloc(sizeof(t_mapData));
	if (mapData == NULL)
		return (NULL);
	ft_memset(mapData, 0, sizeof(t_mapData));
	mapData->zoom_lvl = 1;
	mapData->x_offset = 525;
	mapData->y_offset = 175;
	mapData->angle = 30;
	mapData->z_min = INT_MAX;
	mapData->z_max = INT_MIN;
	mapData->season = 1;
	mapData->x_angle = 90;
	mapData->y_angle = 90;
	mapData->z_angle = 90;
	get_map_data(&mapData, filename);
	return (mapData);
}
