/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:10:02 by vviterbo          #+#    #+#             */
/*   Updated: 2024/12/05 19:09:08 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_coor	scale_vector(t_coor base, t_coor tip, float scale);
t_coor	pxl2pt(t_coor xy, t_params *params);
t_coor	pt2pxl(t_coor xy, t_params *params);
void	update_range_shift(t_imx *data, int dir);
int		free_all(t_imx *data);
void	update_range_zoom(t_imx *data, int mousecode, t_coor mouse);

t_coor	scale_vector(t_coor base, t_coor tip, float scale)
{
	t_coor	new_vector;

	new_vector.x = (tip.x - base.x) * (double)scale + base.x;
	new_vector.y = (tip.y - base.y) * (double)scale + base.y;
	return (new_vector);
}

t_coor	pxl2pt(t_coor xy, t_params *params)
{
	xy.x = xy.x * (params->max.x - params->min.x) / (double)params->window_size.x;
	xy.y = xy.y * (params->max.y - params->min.y) / (double)params->window_size.y;
	xy.x = xy.x + params->min.x;
	xy.y = xy.y + params->min.y;
	return (xy);
}

t_coor	pt2pxl(t_coor xy, t_params *params)
{
	xy.x = xy.x - params->min.x;
	xy.y = xy.y - params->min.y;
	xy.x = xy.x * (double)params->window_size.x / (params->max.x - params->min.x);
	xy.y = xy.y * (double)params->window_size.y / (params->max.y - params->min.y);
	return (xy);
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
	//double	xtmp;
	//double	ytmp;

	scale = 1;
	if (mousecode == ZOOM_IN)
		scale = ZOOM_SCALE;
	else if (mousecode == ZOOM_OUT)
		scale = 1 / ZOOM_SCALE;
	else
		return ;
	printf("-> mouse = %f, %f\n", mouse.x, mouse.y);
	printf("init : min = %f, %f\tmax = %f, %f\tmouse = %f, %f\n", data->params->min.x, data->params->min.y, data->params->max.x, data->params->max.y, pt2pxl(mouse, data->params).x, pt2pxl(mouse, data->params).y);
	data->params->min = scale_vector(mouse, data->params->min, scale);
	//data->params->min.x = xtmp;
	
	data->params->max = scale_vector(mouse, data->params->max, scale);
	//data->params->max = scale_vector(mouse, data->params->max, scale);
	printf("init : min = %f, %f\tmax = %f, %f\tmouse = %f, %f\n", data->params->min.x, data->params->min.y, data->params->max.x, data->params->max.y, pt2pxl(mouse, data->params).x, pt2pxl(mouse, data->params).y);
	printf("window size = %f, %f\n", data->params->window_size.x, data->params->window_size.y);
	return ;
}
