/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 22:34:51 by glevin            #+#    #+#             */
/*   Updated: 2024/09/14 00:56:43 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	init_mapData(t_mapData *mapData, char *filename)
{
	mapData->zoom_lvl = 3;
	mapData->x_offset = 300;
	mapData->y_offset = 0;
	get_map_data(mapData, filename);
}

// t_pointData	*update_points(t_pointData *pData, t_mapData *mapData)
// {
// 	int	i;
// 	int row;
// 	int column;

// 	i = 0;
// 	row = 0;
// 	column = 0;
// 	while (i < mapData->vertices)
// 	{
// 		pData[i].x = mapData->x_offset + column * mapData->zoom_lvl;
// 		pData[i].y = mapData->y_offset + row * mapData->zoom_lvl;
// 		i++;
// 	}
// 	return (pData);
// }

void	redraw(t_mlxData *img, t_pointData *pData, t_mapData mapData)
{
	mlx_clear_window(img->mlx, img->win);
	// pData = update_points(pData, mapData);
	render_points_to_image(pData, img, mapData.vertices);
	render_lines_to_image(pData, img, mapData);
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
}

int	main(int argc, char **argv)
{
	t_mlxData	img;
	t_pointData	*pData;
	t_mapData	mapData;

	if (argc != 2)
		return (1);
	ft_memset(&mapData, 0, sizeof(t_mapData));
	init_window(&img, &mapData);
	init_mapData(&mapData, argv[1]);
	pData = parse_input(argv[1], &mapData);
	render_points_to_image(pData, &img, mapData.vertices);
	render_lines_to_image(pData, &img, mapData);
	mlx_put_image_to_window(img.mlx, img.win, img.img, 0, 0);
	mlx_loop(img.mlx);
	return (0);
}
