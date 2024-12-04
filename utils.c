/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:10:02 by vviterbo          #+#    #+#             */
/*   Updated: 2024/12/04 13:42:15 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_coor	scale_vector(t_coor base, t_coor tip, float scale);
t_coor	pxl2pt(t_coor xy, t_params *params);
void	update_range_shift(t_imx *data, int dir);
int		free_all(t_imx *data);
void	update_range_zoom(t_imx *data, int mousecode, t_coor mouse);

t_coor	scale_vector(t_coor base, t_coor tip, float scale)
{
	t_coor	new_vector;

	new_vector.x = (tip.x - base.x) * scale + base.x;
	new_vector.y = (tip.y - base.y) * scale + base.y;
	return (new_vector);
}

t_coor	pxl2pt(t_coor xy, t_params *params)
{
	xy.x = xy.x * (params->max.x - params->min.x) / params->window_size.x;
	xy.y = xy.y * (params->max.y - params->min.y) / params->window_size.y;
	xy.x = xy.x + params->min.x;
	xy.y = xy.y + params->min.y;
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

	scale = 1;
	if (mousecode == ZOOM_IN)
		scale = ZOOM_SCALE;
	else if (mousecode == ZOOM_OUT)
		scale = 1 / ZOOM_SCALE;
	data->params->min = scale_vector(mouse, data->params->min, scale);
	data->params->max = scale_vector(mouse, data->params->max, scale);
	return ;
}
