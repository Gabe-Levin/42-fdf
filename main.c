/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 22:34:51 by glevin            #+#    #+#             */
/*   Updated: 2024/10/03 22:52:27 by glevin           ###   ########.fr       */
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
	mapData->zoom_lvl = 1;
	mapData->x_offset = 525;
	mapData->y_offset = 175;
	mapData->angle = 30;
	get_map_data(&mapData, filename);
	return (mapData);
}

void	draw_text(t_mlxData *mlxData)
{
	mlx_string_put(mlxData->mlx, mlxData->win, 10, 20, 0xFFFFFF,
		"Translate image: Arrow keys or wasd");
	mlx_string_put(mlxData->mlx, mlxData->win, 10, 40, 0xFFFFFF,
		"Rotate image: Q, E");
	mlx_string_put(mlxData->mlx, mlxData->win, 10, 60, 0xFFFFFF,
		"Adjust zoom:+,-");
}

void	redraw(t_mlxData *mlxData, t_pointData *pData, t_mapData *mapData)
{
	mlx_clear_window(mlxData->mlx, mlxData->win);
	if (mlxData->img)
		mlx_destroy_image(mlxData->mlx, mlxData->img);
	mlxData->img = mlx_new_image(mlxData->mlx, mlxData->win_width,
			mlxData->win_height);
	project_iso(pData, mapData);
	draw_points(pData, mlxData, mapData->vertices);
	// draw_lines(pData, mlxData, mapData);
	mlx_put_image_to_window(mlxData->mlx, mlxData->win, mlxData->img, 0, 0);
	draw_text(mlxData);
}

void	center_points(t_pointData *pData, t_mapData *mapData)
{
	int	default_zoom;

	// default_zoom = (int)(300 / (pData[mapData->vertices - 1].dy
	// - pData[0].dy));
	default_zoom = 20;
	printf("default zoom: %d\n", default_zoom);
	printf("mapData->vertices: %d\n", mapData->vertices);
	if (default_zoom == 0)
		mapData->zoom_lvl = 1;
	else
		mapData->zoom_lvl = default_zoom;
	project_iso(pData, mapData);
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
	center_points(pData, mapData);
	init_hooks(img, mapData, pData);
	draw_points(pData, img, mapData->vertices);
	// draw_lines(pData, img, mapData);
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	mlx_loop(img->mlx);
	free(mapData);
	free(pData);
	free(img);
	return (0);
}
