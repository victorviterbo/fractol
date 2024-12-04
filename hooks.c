/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 12:10:13 by vviterbo          #+#    #+#             */
/*   Updated: 2024/12/04 14:32:38 by vviterbo         ###   ########.fr       */
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
	if (keycode == RIGHT_ARROW)
		update_range_shift(data, 1);
	if (keycode == UP_ARROW)
		update_range_shift(data, 2);
	if (keycode == DOWN_ARROW)
		update_range_shift(data, 3);
	if (keycode == ESC)
		mlx_destroy_window(data->mlx, data->win);
	fill_img(data, data->params);
	mlx_put_image_to_window(data->mlx, data->win,
		data->next_img->img, 0, 0);
	ft_swap_void((void **)&data->curr_img, (void **)&data->curr_img);
	return (0);
}

int	mouse_hook(int mousecode, int x, int y, t_imx *data)
{
	t_coor	mouse;

	mlx_mouse_get_pos(data->win, &x, &y);
	mouse.x = x * (data->params->max.x - data->params->min.x)
		/ data->params->window_size.x + data->params->min.x;
	mouse.y = y * (data->params->max.y - data->params->min.y)
		/ data->params->window_size.y + data->params->min.y;
	update_range_zoom(data, mousecode, mouse);
	fill_img(data, data->params);
	mlx_put_image_to_window(data->mlx, data->win,
		data->next_img->img, 0, 0);
	ft_swap_void((void **)data->curr_img, (void **)&data->next_img);
	return (0);
}
