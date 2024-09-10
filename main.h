/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 00:10:03 by glevin            #+#    #+#             */
/*   Updated: 2024/09/10 02:50:55 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "masterLib/masterLib.h"
# include <fcntl.h>
# include <mlx.h>
# include <stdlib.h>

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

t_pointData	*parseInput(const char *filename);

#endif