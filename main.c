/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 18:56:06 by vviterbo          #+#    #+#             */
/*   Updated: 2024/12/03 00:29:06 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	img_data_fill(t_data *data, int x, int y, float color);
float	map_colors(float color);

int main(void)
{
	t_coor	current;
	void	*mlx;
	t_data	img;
	void	*window;
	int		nsteps;
	t_coor	min;
	t_coor	max;
	t_coor	window_size;

	mlx = mlx_init();
	min.x = -2;
	min.y = -1;
	max.x = 2;
	max.y = 1;
	window_size.x = 2560 / 4;
	window_size.y = 1600 / 4;
	window = mlx_new_window(mlx, window_size.x, window_size.y, "Mandelbrot");
	img.img = mlx_new_image(mlx, window_size.x, window_size.y);
	nsteps = 250;
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	current.x = 0;
	while (current.x < window_size.x)
	{
		current.y = 0;
		while (current.y < window_size.y)
		{
			img_data_fill(&img, current.x, current.y, madelbrot(pxl2pt(current, min, max, window_size), nsteps));
			current.y++;
		}
		current.x++;
	}
	mlx_put_image_to_window(mlx, window, img.img, 0, 0);
	mlx_loop(mlx);
}

void	img_data_fill(t_data *data, int x, int y, float color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = map_colors(color);
	return ;
}

float	map_colors(float color)
{
	int	r;
	int	g;
	int	b;

	if (color < 0.5)
	{
		r = (unsigned char)(255 * (1 - 2 * color));
		g = (unsigned char)(255 * (2 * color));
		b = 0;
	}
	else
	{
		r = 0;
		g = (unsigned char)(255 * (2 - 2 * color));
		b = (unsigned char)(255 * (2 * color - 1));
	}
	return (16777216 + r * 65536 + g * 256 + b);
}
