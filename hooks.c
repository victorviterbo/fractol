/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 12:10:13 by vviterbo          #+#    #+#             */
/*   Updated: 2024/12/03 17:30:51 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_hooks(t_imx *mlx_obj);
int		key_hook(int keycode, t_imx *mlx_obj);
int		mouse_hook(int mousecode, int x, int y, t_imx *mlx_obj);

void	set_hooks(t_imx *mlx_obj)
{
	mlx_hook(mlx_obj->win, 2, 1L<<0, close_free_all, &mlx_obj);
	mlx_key_hook(mlx_obj->win, key_hook, mlx_obj);
	mlx_mouse_hook(mlx_obj->win, mouse_hook, mlx_obj);
}

int	key_hook(int keycode, t_imx *mlx_obj)
{
	if (keycode == LEFT_ARROW)
		update_range_shift(mlx_obj, 0);
	if (keycode == RIGHT_ARROW)
		update_range_shift(mlx_obj, 1);
	if (keycode == UP_ARROW)
		update_range_shift(mlx_obj, 2);
	if (keycode == DOWN_ARROW)
		update_range_shift(mlx_obj, 3);
	if (keycode == ESC)
		close_free_all(mlx_obj);
	fill_img(mlx_obj, mlx_obj->params);
	mlx_put_image_to_window(mlx_obj->mlx, mlx_obj->win, mlx_obj->next_img->img, 0, 0);
	ft_swap_void((void **)&mlx_obj->curr_img, (void **)&mlx_obj->curr_img);
	return (0);
}

int	mouse_hook(int mousecode, int x, int y, t_imx *mlx_obj)
{
	t_coor	mouse;

	mlx_mouse_get_pos(mlx_obj->win, &x, &y);
	mouse.x = x * (mlx_obj->params->max.x - mlx_obj->params->min.x)/ mlx_obj->params->window_size.x;
	mouse.y = y * (mlx_obj->params->max.y - mlx_obj->params->min.y)/ mlx_obj->params->window_size.y;
	update_range_zoom(mlx_obj, mousecode, mouse);
	fill_img(mlx_obj, mlx_obj->params);
	mlx_put_image_to_window(mlx_obj->mlx, mlx_obj->win, mlx_obj->next_img->img, 0, 0);
	ft_swap_void((void **)mlx_obj->curr_img, (void **)&mlx_obj->next_img);
	return (0);
}
