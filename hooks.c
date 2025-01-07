/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 12:10:13 by vviterbo          #+#    #+#             */
/*   Updated: 2024/12/12 14:46:46 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_hooks(t_imx *data);
int		key_hook(int keycode, t_imx *data);
int		mouse_hook(int mousecode, int x, int y, t_imx *data);

void	set_hooks(t_imx *data)
{
	mlx_key_hook(data->win, key_hook, data);
	mlx_mouse_hook(data->win, mouse_hook, data);
	mlx_hook(data->win, 17, 0, free_all, data);
}

int	key_hook(int keycode, t_imx *data)
{
	if (keycode == LEFT_ARROW)
		update_range_shift(data, 0);
	else if (keycode == RIGHT_ARROW)
		update_range_shift(data, 1);
	else if (keycode == UP_ARROW)
		update_range_shift(data, 2);
	else if (keycode == DOWN_ARROW)
		update_range_shift(data, 3);
	else if (keycode == ESC)
		free_all(data);
	else
		return (0);
	update_img(data, data->params);
	mlx_put_image_to_window(data->mlx, data->win,
		data->curr_img->img, 0, 0);
	return (0);
}

int	mouse_hook(int mousecode, int x, int y, t_imx *data)
{
	t_coor	mouse;

	if (mousecode != ZOOM_IN && mousecode != ZOOM_OUT)
		return (0);
	mouse.x = (double)x;
	mouse.y = (double)y;
	mouse = pxl2pt(mouse, data->params);
	mlx_clear_window(data->mlx, data->win);
	update_range_zoom(data, mousecode, mouse);
	update_img(data, data->params);
	mlx_put_image_to_window(data->mlx, data->win,
		data->curr_img->img, 0, 0);
	return (0);
}
