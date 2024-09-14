/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 22:34:51 by glevin            #+#    #+#             */
/*   Updated: 2024/09/14 22:29:42 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_mapData	*init_mapData(char *filename)
{
	t_mapData	*mapData;

	mapData = (t_mapData *)malloc(sizeof(t_mapData));
	if (mapData == NULL)
		return (NULL);
	ft_memset(mapData, 0, sizeof(t_mapData));
	mapData->zoom_lvl = 3;
	mapData->x_offset = 300;
	mapData->y_offset = 0;
	mapData->angle = 0.5236;
	get_map_data(&mapData, filename);
	return (mapData);
}

t_pointData	*update_points(t_pointData *pData, t_mapData *mapData)
{
	int	i;
	int	row;
	int	column;

	i = 0;
	row = 0;
	column = 0;
	while (i < mapData->vertices)
	{
		pData[i].dx++;
		pData[i].x = mapData->x_offset + column * mapData->zoom_lvl;
		pData[i].y = mapData->y_offset + row * mapData->zoom_lvl;
		i++;
	}
	printf("updateP: %d\n",pData[1].dx);
	return (pData);
}

void	redraw(t_mlxData *img, t_pointData *pData, t_mapData *mapData)
{
	mlx_clear_window(img->mlx, img->win);
	pData = update_points(pData, mapData);
	printf("redraw: %d\n",pData[1].dx);
	draw_points(pData, img, mapData->vertices);
	draw_lines(pData, img, mapData);
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
}

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
	init_hooks(img, mapData, pData);
	draw_points(pData, img, mapData->vertices);
	draw_lines(pData, img, mapData);
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	mlx_loop(img->mlx);
	free(mapData);
	free(pData);
	free(img);
	return (0);
}
