/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 21:41:43 by vviterbo          #+#    #+#             */
/*   Updated: 2025/01/20 19:33:46 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		free_all(t_imx *imx);
void	update_range_shift(t_imx *imx, int dir);
void	update_range_zoom(t_imx *imx, int mousecode, t_coor mouse);
void	set_pixel(t_coor pxl, t_imx *imx, t_params *params);
int		map_colors(double color);

void	update_range_zoom(t_imx *imx, int mousecode, t_coor mouse)
{
	float	scale;

	scale = 1;
	if (mousecode == ZOOM_IN)
		scale = ZOOM_SCALE;
	else if (mousecode == ZOOM_OUT)
		scale = 1 / ZOOM_SCALE;
	else
		return ;
	imx->params->min = scale_vector(mouse, imx->params->min, scale);
	imx->params->max = scale_vector(mouse, imx->params->max, scale);
	return ;
}

void	update_range_shift(t_imx *imx, int dir)
{
	t_coor	min;
	t_coor	max;

	min = imx->params->min;
	max = imx->params->max;
	if (dir < 2)
	{
		dir = 2 * dir - 1;
		imx->params->min.x = min.x + dir * ARROW_SCALE * (max.x - min.x);
		imx->params->max.x = max.x + dir * ARROW_SCALE * (max.x - min.x);
	}
	else
	{
		dir = 2 * (dir - 2) - 1;
		imx->params->min.y = min.y + dir * ARROW_SCALE * (max.y - min.y);
		imx->params->max.y = max.y + dir * ARROW_SCALE * (max.y - min.y);
	}
	return ;
}

void	set_pixel(t_coor pxl, t_imx *imx, t_params *params)
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
	dst = imx->curr_img->addr + (int)(pxl.y * imx->curr_img->line_length
			+ pxl.x * (imx->curr_img->bits_per_pixel / 8));
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
	r = (unsigned char)(255 * color);
	g = (unsigned char)(255 * pow(color, 0.01));
	b = (unsigned char)(255 * pow(color, 100));
	a = 0;
	return (a * pow(255, 3) + r * pow(255, 2) + g * pow(255, 1) + b);
}
