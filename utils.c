/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:10:02 by vviterbo          #+#    #+#             */
/*   Updated: 2024/12/03 14:22:57 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_coor	scale_vector(t_coor base, t_coor tip, float scale);
t_coor	pxl2pt(t_coor xy, t_params *params);
void	update_range(t_imx *mlx_obj, int dir);

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

void	update_range(t_imx *mlx_obj, int dir)
{
	t_coor	min;
	t_coor	max;

	min = mlx_obj->params->min;
	max = mlx_obj->params->max;
	if (dir < 2)
	{
		dir = 2 * dir - 1;
		mlx_obj->params->min.x = min.x + dir * ARROW_MOVE * (max.x - min.x);
		mlx_obj->params->max.x = max.x + dir * ARROW_MOVE * (max.x - min.x);
	}
	else
	{
		dir = 2 * (dir - 2) - 1;
		mlx_obj->params->min.y = min.y + dir * ARROW_MOVE * (max.y - min.y);
		mlx_obj->params->max.y = max.y + dir * ARROW_MOVE * (max.y - min.y);
	}
	return ;
}
