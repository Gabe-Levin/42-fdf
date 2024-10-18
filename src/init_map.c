/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 20:28:31 by glevin            #+#    #+#             */
/*   Updated: 2024/10/18 10:36:07 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

void	get_map_data_loop(char **str, t_mapData *m)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i][0] != '\n')
		{
			if (ft_atoi(str[i]) < m->z_min)
				m->z_min = ft_atoi(str[i]);
			if (ft_atoi(str[i]) > m->z_max)
				m->z_max = ft_atoi(str[i]);
			m->vertices++;
		}
		i++;
	}
}

void	get_map_data(t_mapData *m, const char *filename)
{
	int		fd;
	char	*l;
	char	**str;

	fd = open(filename, O_RDONLY);
	l = get_next_line(fd);
	while (l != NULL)
	{
		str = ft_split(l, ' ');
		get_map_data_loop(str, m);
		m->rows++;
		free_split_str(str);
		free(l);
		l = get_next_line(fd);
	}
	free(l);
	m->columns = m->vertices / m->rows;
	close(fd);
}
