/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 18:56:06 by vviterbo          #+#    #+#             */
/*   Updated: 2024/12/04 22:42:53 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double		map_colors(double color);
void		fill_img(t_imx *data, t_params *params);
t_params	*parse_params(char *argv[]);

int main(int argc, char *argv[])
{
	t_imx		*data;

	(void)argc;
	data = ft_calloc(1, sizeof(t_imx));
	data->mlx = mlx_init();
	data->params = parse_params(argv);
	data->curr_img = ft_calloc(1, sizeof(t_data));
	data->curr_img->img = mlx_new_image(data->mlx, data->params->window_size.x, data->params->window_size.y);
	data->next_img = ft_calloc(1, sizeof(t_data));
	data->next_img->img = mlx_new_image(data->mlx, data->params->window_size.x, data->params->window_size.y);
	data->win = mlx_new_window(data->mlx, data->params->window_size.x, data->params->window_size.y, "Mandelbrot");
	fill_img(data, data->params);
	mlx_put_image_to_window(data->mlx, data->win, data->next_img->img, 0, 0);
	set_hooks(data);
	mlx_loop(data->mlx);
	free(data);
	return (0);
}

void	fill_img(t_imx *data, t_params *params)
{
	t_data	*img;
	t_coor	current;
	char	*dst;
	double	color;

	img = data->next_img;
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	current.x = 0;
	current.y = 0;
	while (current.x < params->window_size.x)
	{
		current.y = 0;
		if ((int)current.x % 100 == 0)
			printf("Computing line %i\n", (int)current.x);
		while (current.y < params->window_size.y)
		{
			if (params->ft == MANDELBROT)
				color = madelbrot(pxl2pt(current, params), params->nsteps);
			else if (params->ft == JULIA)
				color = julia(pxl2pt(current, params), params->c0,
					params->nsteps);
			dst = img->addr + (int)(current.y * img->line_length + current.x * (img->bits_per_pixel / 8));
			*(unsigned int *)dst = map_colors(color);
			current.y++;
		}
		current.x++;
	}
	return ;
}

double	map_colors(double color)
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
	int			offset;

	params = ft_calloc(1, sizeof(t_params));
	if (ft_strncmp(argv[1], "MANDELBROT", ft_max(ft_strlen(argv[1]), 11)) == 0)
		params->ft = MANDELBROT;
	else if (ft_strncmp(argv[1], "JULIA", ft_max(ft_strlen(argv[1]), 6)) == 0)
		params->ft = JULIA;
	offset = 2 * (params->ft == JULIA);
	if (params->ft == JULIA)
	{
		params->c0.x = (double)ft_atof(argv[2]);
		params->c0.y = (double)ft_atof(argv[3]);
	}
	params->nsteps = ft_atoi(argv[offset + 2]);
	params->window_size.x = ft_atoi(argv[offset + 3]);
	params->window_size.y = ft_atoi(argv[offset + 4]);
	params->min.x = ft_atoi(argv[offset + 5]);
	params->min.y = ft_atoi(argv[offset + 6]);
	if (ft_atoi(argv[offset + 7]) != '*')
		params->max.x = ft_atoi(argv[offset + 7]);
	else
		params->max.x = ft_atoi(argv[offset + 8]) * params->window_size.x / params->window_size.y;
	if (ft_atoi(argv[offset + 8]) != '*')
		params->max.y = ft_atoi(argv[offset + 8]);
	else
		params->max.y = ft_atoi(argv[offset + 7]) * params->window_size.y / params->window_size.x;
	return (params);
}
