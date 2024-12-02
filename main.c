/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 18:56:06 by vviterbo          #+#    #+#             */
/*   Updated: 2024/12/02 19:10:09 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	img_data_fill(t_data *data, int x, int y, float color);
float	map_colors(float color);

int main(void)
{
	int		i;
	int		j;
	void	*mlx;
	t_data	img;
	void	*window;
	int		*dims;
	int		nsteps;
	float	scale;

	mlx = mlx_init();
	dims = ft_calloc(4, sizeof(int));
	dims[0] = -2560 / 8;
	dims[1] = -1600 / 8;
	dims[2] = 2560 / 8;
	dims[3] = 1600 / 8;
	window = mlx_new_window(mlx, dims[2] - dims[0], dims[3] - dims[1], "Mandelbrot");
	img.img = mlx_new_image(mlx, dims[2] - dims[0], dims[3] - dims[1]);
	nsteps = 250;
	scale = 200;
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	i = 0;
	while (i < dims[2] - dims[0])
	{
		j = 0;
		while (j < dims[3] - dims[1])
		{
			img_data_fill(&img, i, j, madelbrot((float)(i + dims[0])/(scale), (float)(j + dims[1])/(scale), nsteps));
			j++;
		}
		i++;
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
