/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 18:56:06 by vviterbo          #+#    #+#             */
/*   Updated: 2024/12/03 14:35:56 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		img_data_fill(t_data *data, int x, int y, float color);
float		map_colors(float color);
void		fill_img(t_imx *mlx_obj, t_params *params);
t_params	*parse_params(char *argv[]);

int main(int argc, char *argv[])
{
	t_imx		*mlx_obj;
	t_data		*img;
	t_params	*params;

	(void)argc;
	params = parse_params(argv);
	mlx_obj = ft_calloc(1, sizeof(t_imx));
	mlx_obj->curr_img = ft_calloc(1, sizeof(t_data));
	mlx_obj->next_img = ft_calloc(1, sizeof(t_data));
	mlx_obj->params = params;
	mlx_obj->mlx = mlx_init();
	mlx_obj->win = mlx_new_window(mlx_obj->mlx, params->window_size.x, params->window_size.y, "Mandelbrot");
	img->img = mlx_new_image(mlx_obj->mlx, params->window_size.x, params->window_size.y);
	mlx_obj->curr_img = &img;
	fill_img(mlx_obj, params);
	mlx_put_image_to_window(mlx_obj->mlx, mlx_obj->win, img->img, 0, 0);
	set_hooks(mlx_obj);
	mlx_loop(mlx_obj->mlx);
}

void	fill_img(t_imx *mlx_obj, t_params *params)
{
	t_data	*img;
	t_coor	current;
	char	*dst;
	float	color;

	img = mlx_obj->next_img;
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
	current.x = 0;
	while (current.x < params->window_size.x)
	{
		current.y = 0;
		while (current.y < params->window_size.y)
		{
			img_data_fill(&img, current.x, current.y, madelbrot(pxl2pt(current, params), params->nsteps));
			dst = img->addr + (int)(current.y * img->line_length + current.x * (img->bits_per_pixel / 8));
			*(unsigned int *)dst = map_colors(color);
			current.y++;
		}
		current.x++;
	}
	return (img);
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


t_params	*parse_params(char *argv[])
{
	t_params	*params;

	params = ft_calloc(1, sizeof(t_params));
	if (ft_strncmp(argv[1], "MANDELBROT", ft_max(ft_strlen(argv[1]), 11)) == 0)
		params->ft = MANDELBROT;
	else if (ft_strncmp(argv[1], "JULIA", ft_max(ft_strlen(argv[1]), 6)) == 0)
		params->ft = JULIA;
	params->nsteps = ft_atoi(argv[2]);
	params->window_size.x = ft_atoi(argv[3]);
	params->window_size.y = ft_atoi(argv[4]);
	params->min.x = ft_atoi(argv[5]);
	params->min.y = ft_atoi(argv[6]);
	if (ft_atoi(argv[7]) != '*')
		params->max.x = ft_atoi(argv[7]);
	else
		params->max.x = ft_atoi(argv[8]) * params->window_size.x / params->window_size.y;
	if (ft_atoi(argv[8]) != '*')
		params->max.y = ft_atoi(argv[8]);
	else
		params->max.y = ft_atoi(argv[7]) * params->window_size.y / params->window_size.x;
	return (params);
}
