/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 21:41:43 by vviterbo          #+#    #+#             */
/*   Updated: 2025/11/13 10:28:14 by victorviter      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		free_all(t_imx *imx);
void	update_range_shift(t_imx *imx, int dir);
void	update_range_zoom(t_imx *imx, int mousecode, t_coor mouse);
void	set_pixel(t_coor pxl, t_imx *imx, t_params *params);
int		map_colors(t_imx *imx, double color);

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
	pxl.y = imx->params->window_size.y - pxl.y;
	dst = imx->curr_img->addr + (int)(pxl.y * imx->curr_img->line_length
			+ pxl.x * (imx->curr_img->bits_per_pixel / 8));
	*(unsigned int *)dst = map_colors(imx, color);
	return ;
}

int	map_colors(t_imx *imx, double color)
{
	unsigned char	r = 0;
	unsigned char	g = 0;
	unsigned char	b = 0;

	if (color >= 0.99)
		return (0);
	if (imx->params->coloring_scheme == 0)
	{
		color = color * 6.0;
		if (color < 1.0)
		{
			r = 255;
			g = (int)(color * 255);
		}
		else if (color < 2.0)
		{
			r = (int)((2.0f - color) * 255);
			g = 255;
		}
		else if (color < 3.0)
		{
			g = 255;
			b = (int)((color - 2.0f) * 255);
		}
		else if (color < 4.0) {
			g = (int)((4.0f - color) * 255);
			b = 255;
		}
		else if (color < 5.0)
		{
			r = (int)((color - 4.0f) * 255);
			b = 255;
		}
		else
		{
			r = 255;
			b = (int)((6.0f - color) * 255);
		}
		return (r << 16 | g << 8 | b);
	}
	else if (imx->params->coloring_scheme == 1)
	{
		r = ((color * 0.7 + 0.4) / pow(255, 3)) * pow(255, 4);
		g = 255 * color;
		b = 255 * ((1 - color * 0.7 + 0.3) / pow(255, 1)) * pow(255, 2);
		return (r << 16 | g << 8 | b);
	}
	else if (imx->params->coloring_scheme == 2)
	{
		if (color < 0.5)
		{
			r = 255 * (0.2 + color * 1.2);
			g = 255 * (0.1 + color * 0.8);
			b = 255 * (color - 0.5);
		}
		else
		{
			r = 255 * (1.8 - color * 0.8);
			g = 255 * (color);
			b = 255 * (color - 0.5);
		}
		return (r << 16 | g << 8 | b);
	}
	else if (imx->params->coloring_scheme == 3)
	{
		r = (color / pow(255, 3)) * pow(255, 4);
		g = (color / pow(255, 2)) * pow(255, 3);
		b = (color / pow(255, 1)) * pow(255, 2);
		return (r << 16 | g << 8 | b);
	}
	else if (imx->params->coloring_scheme == 4)
	{
		if (color < 4)
		{
			r = 0;
			g = (int)(color * 1.5 * 255);
			b = (int)(color * 2.0 * 255);
		}
		else if (color < 0.7)
		{
			color = (color - 0.4) / 0.3;
			r = (int)(color * 0.8 * 255);
			g = (int)((1.0 - color * 0.5) * 255);
			b = 255;
		}
		else
		{
			color = (color - 0.7) / 0.3;
			r = (int)((0.8 + color * 0.2) * 255);
			g = (int)((0.5 + color * 0.5) * 255);
			b = 255;
		}
		return (r << 16 | g << 8 | b);
	}
	else
	{
		color = 1 - color;
		r = (unsigned char)(255 * (1 - pow(color, 2)));
		g = (unsigned char)(255 * pow(color, 0.5));
		b = (unsigned char)(255 * pow(color, 1.5));
		return (r << 16 | g << 8 | b);
	}
}
