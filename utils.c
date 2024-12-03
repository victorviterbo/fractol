/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:10:02 by vviterbo          #+#    #+#             */
/*   Updated: 2024/12/03 18:16:49 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_coor	scale_vector(t_coor base, t_coor tip, float scale);
t_coor	pxl2pt(t_coor xy, t_params *params);
void	update_range_shift(t_imx *mlx_obj, int dir);
int		close_free_all(t_imx *mlx_obj);
void	update_range_zoom(t_imx *mlx_obj, int mousecode, t_coor mouse);

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

void	update_range_shift(t_imx *mlx_obj, int dir)
{
	t_coor	min;
	t_coor	max;

	min = mlx_obj->params->min;
	max = mlx_obj->params->max;
	if (dir < 2)
	{
		dir = 2 * dir - 1;
		mlx_obj->params->min.x = min.x + dir * ARROW_SCALE * (max.x - min.x);
		mlx_obj->params->max.x = max.x + dir * ARROW_SCALE * (max.x - min.x);
	}
	else
	{
		dir = 2 * (dir - 2) - 1;
		mlx_obj->params->min.y = min.y + dir * ARROW_SCALE * (max.y - min.y);
		mlx_obj->params->max.y = max.y + dir * ARROW_SCALE * (max.y - min.y);
	}
	return ;
}

int	close_free_all(t_imx *mlx_obj)
{
	mlx_destroy_image(mlx_obj->mlx, mlx_obj->curr_img->img);
	mlx_destroy_image(mlx_obj->mlx, mlx_obj->next_img->img);
	free(mlx_obj->curr_img);
	free(mlx_obj->next_img);
	free(mlx_obj->params);
	mlx_destroy_window(mlx_obj->mlx, mlx_obj->win);
	free(mlx_obj);
	exit(0);
}


void	update_range_zoom(t_imx *mlx_obj, int mousecode, t_coor mouse)
{
	float	scale;
	//t_coor	tmp;

	printf("mousecode = %i\n", mousecode);
	if (mousecode == ZOOM_IN)
		scale = ZOOM_SCALE;
	else
		scale = 1 / ZOOM_SCALE;
	printf("scale = %f", scale);
	printf("init dimmenssions : %f, %f, %f, %f; mouse = %f, %f\n", mlx_obj->params->min.x, mlx_obj->params->min.y, mlx_obj->params->max.x, mlx_obj->params->max.y, mouse.x, mouse.y);
	printf("old diagonal = %f\n", hypot(mlx_obj->params->max.x - mlx_obj->params->min.x, mlx_obj->params->max.x - mlx_obj->params->min.x));
	mouse = scale_vector(mouse, mlx_obj->params->min, scale);
	mlx_obj->params->max = scale_vector(mlx_obj->params->min, mlx_obj->params->max, scale);
	printf("final dimmenssions : %f, %f, %f, %f; mouse = %f, %f\n", mlx_obj->params->min.x, mlx_obj->params->min.y, mlx_obj->params->max.x, mlx_obj->params->max.y, mouse.x, mouse.y);
	printf("new diagonal = %f\n", hypot(mlx_obj->params->max.x - mlx_obj->params->min.x, mlx_obj->params->max.x - mlx_obj->params->min.x));
	return ;
}
