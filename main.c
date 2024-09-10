/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 22:34:51 by glevin            #+#    #+#             */
/*   Updated: 2024/09/09 22:28:21 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void draw_square(char *img_data, int img_width, int square_size, int start_x, int start_y, int color)
{
    int bits_per_pixel = 32;
    int bytes_per_pixel = bits_per_pixel / 8;
    int line_length = img_width * bytes_per_pixel;

    for (int y = 0; y < square_size; y++)
    {
        for (int x = 0; x < square_size; x++)
        {
            int pixel = (y + start_y) * line_length + (x + start_x) * bytes_per_pixel;
            *(unsigned int *)(img_data + pixel) = color;
        }
    }
}
#include <stdio.h>
int	main(void)
{
	void *mlx;
	void *win;
	void *img;
	char *img_data;
	int bits_per_pixel;
	int line_length;
	int endian;

	mlx = mlx_init();
	if (!mlx)
		return (1);

	win = mlx_new_window(mlx, 800, 600, "FDF Test");
	if (!win)
	{
		free(mlx);
		return (1);
	}

	img = mlx_new_image(mlx, 800, 600);
	img_data = mlx_get_data_addr(img, &bits_per_pixel, &line_length, &endian);

    // Draw a 50x50 red square starting at (100, 100)
    draw_square(img_data, 800, 50, 100, 100, 0x00FF0000);

    // Draw another 50x50 blue square starting at (300, 200)
    draw_square(img_data, 800, 50, 300, 200, 0x0000FF00);
    
	mlx_put_image_to_window(mlx, win, img, 0, 0);

	mlx_loop(mlx);

	return (0);
}