/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 00:10:03 by glevin            #+#    #+#             */
/*   Updated: 2024/09/20 12:43:05 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "masterLib/masterLib.h"
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdlib.h>

# define WINDOW_HEIGHT 650
# define WINDOW_WIDTH 1050
# define M_PI 3.14159265358979323846

typedef struct s_pointData
{
	int			x;
	int			y;
	int			z;
	int			dx;
	int			dy;
	int			color;
	int			row;
	int			column;
}				t_pointData;

typedef struct s_mapData
{
	int			rows;
	int			columns;
	int			vertices;
	int			zoom_lvl;
	int			x_offset;
	int			y_offset;
	double		angle;

}				t_mapData;

typedef struct s_mlxData
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			win_width;
	int			win_height;
}				t_mlxData;

typedef struct s_parse_vars
{
	int			pid;
	int			row;
	int			col;
}				t_parse_vars;

typedef struct s_hook_vars
{
	t_pointData	*pData;
	t_mapData	*mapData;
	t_mlxData	*mlxData;
}				t_hook_vars;

t_pointData		*init_points(const char *filename, t_mapData *mapData);
int				close_window(t_mlxData *img);
void			read_input(const char *filename, t_pointData *pData);
int				key_hooks(int keycode, t_hook_vars *hook_vars);
t_mlxData		*init_image(void);
void			put_pixel_to_image(t_mlxData *img, int x, int y, int color);
void			draw_points(t_pointData *pData, t_mlxData *img,
					int numVertices);
void			bresenham(t_mlxData *img, t_pointData p1, t_pointData p2);
void			draw_lines(t_pointData *pData, t_mlxData *img,
					t_mapData *mapData);
void			get_map_data(t_mapData **mapData, const char *filename);
void			init_hooks(t_mlxData *img, t_mapData *mapData,
					t_pointData *pdata);
void			redraw(t_mlxData *img, t_pointData *pData, t_mapData *mapData);
void			update_all_points(t_pointData *pData, t_mapData *mapData);

#endif
