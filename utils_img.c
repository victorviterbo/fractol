/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 21:41:43 by vviterbo          #+#    #+#             */
/*   Updated: 2024/12/10 14:47:07 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		free_all(t_imx *data);
void	update_range_shift(t_imx *data, int dir);
void	update_range_zoom(t_imx *data, int mousecode, t_coor mouse);
void	set_pixel(t_coor pxl, t_imx *data, t_params *params);
int		map_colors(double color);

int	free_all(t_imx *data)
{
	mlx_destroy_image(data->mlx, data->curr_img->img);
	mlx_destroy_image(data->mlx, data->next_img->img);
	free(data->curr_img);
	free(data->next_img);
	free(data->params);
	exit(0);
}

void	update_range_zoom(t_imx *data, int mousecode, t_coor mouse)
{
	float	scale;

	scale = 1;
	if (mousecode == ZOOM_IN)
		scale = ZOOM_SCALE;
	else if (mousecode == ZOOM_OUT)
		scale = 1 / ZOOM_SCALE;
	else
		return ;
	data->params->min = scale_vector(mouse, data->params->min, scale);
	data->params->max = scale_vector(mouse, data->params->max, scale);
	return ;
}

void	update_range_shift(t_imx *data, int dir)
{
	t_coor	min;
	t_coor	max;

	min = data->params->min;
	max = data->params->max;
	if (dir < 2)
	{
		dir = 2 * dir - 1;
		data->params->min.x = min.x + dir * ARROW_SCALE * (max.x - min.x);
		data->params->max.x = max.x + dir * ARROW_SCALE * (max.x - min.x);
	}
	else
	{
		dir = 2 * (dir - 2) - 1;
		data->params->min.y = min.y + dir * ARROW_SCALE * (max.y - min.y);
		data->params->max.y = max.y + dir * ARROW_SCALE * (max.y - min.y);
	}
	return ;
}

void	set_pixel(t_coor pxl, t_imx *data, t_params *params)
{
	double	color;
	char	*dst;

	color = 0;
	if (params->ft == MANDELBROT)
		color = madelbrot(pxl2pt(pxl, params), params->nsteps);
	else if (params->ft == JULIA)
		color = julia(pxl2pt(pxl, params), params->c0, params->nsteps);
	else if (params->ft == BURNING_SHIP)
		color = burning_ship(pxl2pt(pxl, params), params->nsteps);
	dst = data->next_img->addr + (int)(pxl.y * data->next_img->line_length
			+ pxl.x * (data->next_img->bits_per_pixel / 8));
	*(unsigned int *)dst = map_colors(color);
	return ;
}

int	map_colors(double color)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned char	a;

	color = 1 - ft_min(ft_max(color, 0), 1);
	r = 0;
	g = (unsigned char)(255 * 0.01 * color);
	b = (unsigned char)(255 * pow(color, 10));
	a = 0;
	return (a * pow(255, 3) + r * pow(255, 2) + g * pow(255, 1) + b);
}
