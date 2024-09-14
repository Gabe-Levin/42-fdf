/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 22:34:51 by glevin            #+#    #+#             */
/*   Updated: 2024/09/15 00:36:29 by glevin           ###   ########.fr       */
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
	mapData->zoom_lvl = 10;
	mapData->x_offset = 300;
	mapData->y_offset = 300;
	mapData->angle = 0.5236;
	get_map_data(&mapData, filename);
	return (mapData);
}

void	redraw(t_mlxData *mlxData, t_pointData *pData, t_mapData *mapData)
{
	mlx_clear_window(mlxData->mlx, mlxData->win);
	if (mlxData->img)
		mlx_destroy_image(mlxData->mlx, mlxData->img);
	mlxData->img = mlx_new_image(mlxData->mlx, mlxData->win_width,
			mlxData->win_height);
	update_all_points(pData, mapData);
	// read_input("./maps/42.fdf", pData, mapData);
	draw_points(pData, mlxData, mapData->vertices);
	draw_lines(pData, mlxData, mapData);
	mlx_put_image_to_window(mlxData->mlx, mlxData->win, mlxData->img, 0, 0);
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
