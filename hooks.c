/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 12:10:13 by vviterbo          #+#    #+#             */
/*   Updated: 2024/12/11 11:48:46 by vviterbo         ###   ########.fr       */
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
	ft_printf("keycode = %i\n", keycode);
	if (keycode == LEFT_ARROW)
		update_range_shift(data, 0);
	if (keycode == RIGHT_ARROW)
		update_range_shift(data, 1);
	if (keycode == UP_ARROW)
		update_range_shift(data, 2);
	if (keycode == DOWN_ARROW)
		update_range_shift(data, 3);
	if (keycode == ESC)
		mlx_destroy_window(data->mlx, data->win);
	else
		return (0);
	update_img(data, data->params);
	mlx_put_image_to_window(data->mlx, data->win,
		data->next_img->img, 0, 0);
	ft_swap_void((void **)&data->curr_img, (void **)&data->curr_img);
	return (0);
}

int	mouse_hook(int mousecode, int x, int y, t_imx *data)
{
	t_coor	mouse;

	ft_printf("mousecode = %i\n", mousecode);
	if (mousecode != ZOOM_IN && mousecode != ZOOM_OUT)
		return (0);
	y = data->params->window_size.y - y;
	mouse.x = (double)x;
	mouse.y = (double)y;
	mouse = pxl2pt(mouse, data->params);
	update_range_zoom(data, mousecode, mouse);
	update_img(data, data->params);
	mlx_put_image_to_window(data->mlx, data->win,
		data->next_img->img, 0, 0);
	ft_swap_void((void **)data->curr_img, (void **)&data->next_img);
	return (0);
}
