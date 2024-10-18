/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 00:10:03 by glevin            #+#    #+#             */
/*   Updated: 2024/10/18 14:21:06 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "../masterLib/masterLib.h"
# include "colors.h"
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <mlx.h>
# include <stdlib.h>

# define WINDOW_HEIGHT 650
# define WINDOW_WIDTH 1050
# define M_PI 3.14159265358979323846

# define KEY_ESC 65307
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_E 101
# define KEY_Q 113
# define KEY_Z 122
# define KEY_X 120
# define KEY_O 111
# define KEY_P 112
# define KEY_K 107
# define KEY_L 108
# define KEY_N 110
# define KEY_M 109
# define KEY_1 49
# define KEY_2 50
# define KEY_3 51
# define KEY_4 52
# define KEY_5 53

typedef struct s_pointData
{
	int			x;
	int			y;
	int			z;
	int			rx;
	int			ry;
	int			rz;
	int			dx;
	int			dy;
	int			color;
	int			row;
	int			column;
	int			color_given;

}				t_pointData;

typedef struct s_mapData
{
	int			rows;
	int			columns;
	int			vertices;
	int			zoom_lvl;
	int			x_offset;
	int			y_offset;
	int			z_max;
	int			z_min;
	double		angle;
	int			season;
	int			extrusion_factor;
	double		x_angle;
	double		y_angle;
	double		z_angle;
	int			x_center;
	int			y_center;
	int			z_center;
	int			projection;

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
	t_pointData	*p;
	t_mapData	*m;
	t_mlxData	*mlx;
}				t_hook_vars;

t_pointData		*init_points(const char *filename, t_mapData *m);
int				close_window(t_hook_vars *hook_vars);
void			read_input(const char *filename, t_pointData *p);
int				key_hooks(int keycode, t_hook_vars *hook_vars);
t_mlxData		*init_image(void);
void			put_pixel_to_image(t_mlxData *img, int x, int y, int color);
void			draw_points(t_pointData *p, t_mlxData *img, t_mapData *m);
void			bresenham(t_mlxData *img, t_pointData *p1, t_pointData *p2);
void			draw_lines(t_pointData *p, t_mlxData *img, t_mapData *m);
void			get_map_data(t_mapData *m, const char *filename);
void			init_hooks(t_mlxData *img, t_mapData *m, t_pointData *pdata);
void			redraw(t_mlxData *img, t_pointData *p, t_mapData *m);
void			project(t_pointData *p, t_mapData *m);
void			free_split_str(char **str);
int				get_color(t_pointData *p1, t_pointData *p2, double ratio);
void			set_point_color(t_pointData *p, t_mapData *m);
void			rotate_points(t_pointData *p, t_mapData *m);
void			translate_back(t_pointData *p, t_mapData *m);
void			translate_to_origin(t_pointData *p, t_mapData *m);
int				hex_to_int(const char *hex_str);
int				is_valid_input(char *s);
t_mapData		*init_map(char *filename);
void			center_points(t_pointData *p, t_mapData *m);
void			set_offsets(t_pointData *p, t_mapData *m);
int				is_valid_map(int argc, char *filename);

#endif
