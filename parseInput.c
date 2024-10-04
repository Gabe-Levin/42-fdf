/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseInput.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 00:08:45 by glevin            #+#    #+#             */
/*   Updated: 2024/10/04 19:31:54 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

void	project_iso(t_pointData *pData, t_mapData *mapData)
{
	int		i;
	int		x;
	int		y;
	int		z;
	float	rad;

	i = 0;
	rad = mapData->angle * (M_PI / 180.0);
	while (i < mapData->vertices)
	{
		x = pData[i].x * mapData->zoom_lvl;
		y = pData[i].y * mapData->zoom_lvl;
		z = pData[i].z * mapData->extrusion_factor;
		pData[i].dx = (x - y) * cos(rad) + mapData->x_offset;
		pData[i].dy = -z + (x + y) * sin(rad) + mapData->y_offset;
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
		pData[vars.pid].color_given = 1;
		free_split_str(c);
	}
	else
	{
		pData[vars.pid].z = ft_atoi(s);
	}
	pData[vars.pid].x = vars.col;
	pData[vars.pid].y = vars.row;
}

int	is_valid_input(char *s)
{
	if (s[0] == ' ' || s[0] == '\n')
	{
		return (0);
	}
	return (1);
}

void	read_input(const char *filename, t_pointData *pData)
{
	int				fd;
	char			*l;
	char			**str;
	t_parse_vars	vars;
	int				i;

	vars.pid = 0;
	vars.row = 0;
	fd = open(filename, O_RDONLY);
	l = get_next_line(fd);
	while (l != NULL)
	{
		str = ft_split(l, ' ');
		vars.col = 0;
		i = 0;
		while (str[i])
		{
			if (str[i][0] != '\n')
			{
				set_point_xyz(str[vars.col], vars, pData);
				vars.col++;
				vars.pid++;
			}
			i++;
		}
		free_split_str(str);
		free(l);
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

t_pointData	*init_points(const char *filename, t_mapData *mapData)
{
	t_pointData	*pData;

	pData = (t_pointData *)malloc(sizeof(t_pointData) * mapData->vertices);
	if (!pData)
	{
		return (NULL);
	}
	ft_memset(pData, 0, sizeof(t_pointData) * mapData->vertices);
	read_input(filename, pData);
	project_iso(pData, mapData);
	return (pData);
}
