/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseInput.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 00:08:45 by glevin            #+#    #+#             */
/*   Updated: 2024/10/06 20:34:07 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/main.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

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
