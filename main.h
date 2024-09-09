/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 00:10:03 by glevin            #+#    #+#             */
/*   Updated: 2024/09/09 02:48:31 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

#include <fcntl.h>
#include <mlx.h>
#include <stdlib.h>
#include "masterLib/masterLib.h"

typedef struct s_pointData
{
	int		x;
	int		y;
	int		z;
	int		dx;
	int		dy;
}			t_pointData;

t_pointData	*parseInput(const char *filename);

#endif