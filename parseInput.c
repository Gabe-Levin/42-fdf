/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseInput.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 00:08:45 by glevin            #+#    #+#             */
/*   Updated: 2024/09/16 02:28:52 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

void	update_all_points(t_pointData *pData, t_mapData *mapData)
{
	int		i;
	int		temp_x;
	int		temp_y;
	float	rad;

	i = 0;
	rad = mapData->angle * (M_PI / 180.0);
	while (i < mapData->vertices)
	{
		temp_x = pData[i].x * mapData->zoom_lvl;
		temp_y = pData[i].y * mapData->zoom_lvl;
		// printf("BEFORE: \n x: %i\n y: %i\n dx: %i\n dy: %i\n --------\n",
		// 	pData[i].x, temp_y, pData[i].dx, pData[i].dy);
		// printf("BEFORE: \n zoom_lvl: %i\n --------\n", mapData->zoom_lvl);
		pData[i].dx = (temp_x * cos(rad) - temp_y
				* cos(rad)) + mapData->x_offset;
		pData[i].dy = (temp_x * sin(rad) + temp_y
				* sin(rad) - pData[i].z) + mapData->y_offset;
		// printf("BEFORE: \n zoom_lvl: %i\n --------\n", mapData->zoom_lvl);
		// printf("i: %d\n x: %i\n y: %i\ndx: %i\n dy: %i\n--------\n", i,
		// 	pData[i].x, pData[i].y, pData[i].dx, pData[i].dy);
		i++;
	}
	return ;
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

void	set_point_xyz(char *s, t_parse_vars vars, t_pointData *pData)
{
	char	**c;

	if (ft_strchr(s, ','))
	{
		c = ft_split(s, ',');
		pData[vars.pid].z = ft_atoi(c[0]);
		pData[vars.pid].color = hex_to_int(c[1]);
		// printf("color: 0x%x\n", pData[vars.pid].color);
	}
	else
	{
		pData[vars.pid].z = ft_atoi(s);
	}
	pData[vars.pid].x = vars.col;
	pData[vars.pid].y = vars.row;
	// printf("z: %d\n", pData[vars.pid].z);
	// printf("color: %d\n", pData[vars.pid].color);
}

void	read_input(const char *filename, t_pointData *pData)
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
			set_point_xyz(str[vars.col], vars, pData);
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
	char	**str;

	fd = open(filename, O_RDONLY);
	l = get_next_line(fd);
	while (l != NULL)
	{
		i = 0;
		str = ft_split(l, ' ');
		while (str[i])
		{
			(*mapData)->vertices++;
			i++;
		}
		(*mapData)->rows++;
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
	read_input(filename, pData);
	update_all_points(pData, mapData);
	return (pData);
}
