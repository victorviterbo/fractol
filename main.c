/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 18:56:06 by vviterbo          #+#    #+#             */
/*   Updated: 2024/12/02 14:54:54 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	img_data_fill(t_data *data, int x, int y, int color);

int main(int argc, char *argv[])
{
	int		i;
	int		j;
	void	*mlx;
	t_data	img;
	void	*window;
	int		*dims;
	int		nsteps;
	int		value;

	mlx = mlx_init();
	window = mlx_new_window(mlx, dims[2] - dims[0], dims[3] - dims[1], "Mandelbrot");
	dims = ft_calloc(4, sizeof(int));
	img.img = mlx_new_image(mlx, dims[3] - dims[1], dims[2] - dims[0]);
	//map = ft_calloc((dims[3] - dims[1]) * (dims[2] - dims[0]), sizeof(char));
	nsteps = 255;
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	i = 0;
	while (i < dims[2] - dims[0])
	{
		j = 0;
		while (j < dims[3] - dims[1])
		{
			img_data_fill(&img, i, j, madelbrot(i + dims[0], j + dims[1], nsteps));
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(mlx, window, img.img, 0, 0);
}

void	img_data_fill(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
	return ;
}
