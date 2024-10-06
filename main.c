/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 22:34:51 by glevin            #+#    #+#             */
/*   Updated: 2024/10/06 20:52:41 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/main.h"



int	main(int argc, char **argv)
{
	t_mlxData	*img;
	t_pointData	*pData;
	t_mapData	*mapData;

	if (argc != 2)
		return (1);
	img = init_image();
	mapData = init_mapData(argv[1]);
	pData = init_points(argv[1], mapData);
	center_points(pData, mapData);
	init_hooks(img, mapData, pData);
	draw_points(pData, img, mapData);
	draw_lines(pData, img, mapData);
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	mlx_loop(img->mlx);
	free(mapData);
	free(pData);
	free(img);
	return (0);
}
