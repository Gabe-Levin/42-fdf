/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 00:10:03 by glevin            #+#    #+#             */
/*   Updated: 2024/09/13 15:53:15 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "masterLib/masterLib.h"
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdlib.h>

# define BUFFER_SIZE2 700000

typedef struct s_pointData
{
	int		x;
	int		y;
	int		z;
	int		dx;
	int		dy;
	int		color;
	int		row;
	int		column;
}			t_pointData;

typedef struct s_mapData
{
	int		rows;
	int		columns;
	int		vertices;
	int		zoom_lvl;
	int		x_offset;
	int		y_offset;

}			t_mapData;

typedef struct s_mlxData
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
}			t_mlxData;

t_pointData	*parseInput(const char *filename, t_mapData *mapData);
int			close_window(t_mlxData *img);
int			key_hook(int keycode, t_mlxData *img);
void		init_window(t_mlxData *img, t_mapData *mapData);
void		put_pixel_to_image(t_mlxData *img, int x, int y, int color);
void		render_points_to_image(t_pointData *pData, t_mlxData *img,
				int numVertices);
void		bresenham(t_mlxData *img, t_pointData p1, t_pointData p2);
void		render_lines_to_image(t_pointData *pData, t_mlxData *img,
				t_mapData mapData);
void		get_map_data(t_mapData *mapData, const char *filename);

#endif
