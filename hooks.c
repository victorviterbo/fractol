/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 12:10:13 by vviterbo          #+#    #+#             */
/*   Updated: 2025/11/13 10:27:40 by victorviter      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_hooks(t_imx *imx);
int		key_hook(int keycode, t_imx *imx);
int		mouse_hook(int mousecode, int x, int y, t_imx *imx);

void	set_hooks(t_imx *imx)
{
	mlx_key_hook(imx->win, key_hook, imx);
	mlx_mouse_hook(imx->win, mouse_hook, imx);
	mlx_hook(imx->win, 17, 0, free_all, imx);
}

int	key_hook(int keycode, t_imx *imx)
{
	if (keycode == LEFT_ARROW)
		update_range_shift(imx, 0);
	else if (keycode == RIGHT_ARROW)
		update_range_shift(imx, 1);
	else if (keycode == DOWN_ARROW)
		update_range_shift(imx, 2);
	else if (keycode == UP_ARROW)
		update_range_shift(imx, 3);
	else if (keycode == ESC)
		free_all(imx);
	else if (keycode == C_KEY)
		imx->params->coloring_scheme = (imx->params->coloring_scheme + 1) % N_COLOR_SCHEME;
	else if (keycode == I_KEY)
		return (print_params(imx));
	else
		return (0);
	update_img(imx, imx->params);
	mlx_put_image_to_window(imx->mlx, imx->win,
		imx->curr_img->img, 0, 0);
	return (0);
}

int	mouse_hook(int mousecode, int x, int y, t_imx *imx)
{
	t_coor	mouse;

	if (mousecode != ZOOM_IN && mousecode != ZOOM_OUT && mousecode != RIGHT_CLICK)
		return (0);
	if (mousecode == RIGHT_CLICK && imx->params->ft != JULIA)
		return (0);
	mouse.x = (double)x;
	mouse.y = (double)y;
	mouse = pxl2pt(mouse, imx->params);
	mlx_clear_window(imx->mlx, imx->win);
	if (mousecode == RIGHT_CLICK)
		imx->params->c0 = mouse;
	else
		update_range_zoom(imx, mousecode, mouse);
	update_img(imx, imx->params);
	mlx_put_image_to_window(imx->mlx, imx->win,
		imx->curr_img->img, 0, 0);
	return (0);
}
