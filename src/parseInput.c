/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseInput.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 00:08:45 by glevin            #+#    #+#             */
/*   Updated: 2024/10/10 14:45:49 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

void	set_point_xyz(char *s, t_parse_vars *vars, t_pointData *p)
{
	char	**c;

	if (ft_strchr(s, ','))
	{
		c = ft_split(s, ',');
		p[vars->pid].z = ft_atoi(c[0]);
		p[vars->pid].color = hex_to_int(c[1]);
		p[vars->pid].color_given = 1;
		free_split_str(c);
	}
	else
	{
		p[vars->pid].z = ft_atoi(s);
	}
	p[vars->pid].x = vars->col;
	p[vars->pid].y = vars->row;
}

void	read_input_loop(char **str, t_parse_vars *vars, t_pointData *p)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i][0] != '\n')
		{
			set_point_xyz(str[vars->col], vars, p);
			vars->col++;
			vars->pid++;
		}
		i++;
	}
}

void	read_input(const char *filename, t_pointData *p)
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
		read_input_loop(str, &vars, p);
		free_split_str(str);
		free(l);
		l = get_next_line(fd);
		vars.row++;
	}
	close(fd);
}
