/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 12:10:13 by vviterbo          #+#    #+#             */
/*   Updated: 2024/12/03 14:35:31 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_hooks(t_imx *mlx_obj);
int		key_hook(int keycode, t_imx *mlx_obj);
int		mouse_hook(int keycode, t_imx *mlx_obj);
void	shift_view(t_imx *mlx_obj, int dir);

void	set_hooks(t_imx *mlx_obj)
{
	mlx_hook(mlx_obj->win, 2, 1L<<0, close, &mlx_obj);
	mlx_key_hook(mlx_obj->win, key_hook, mlx_obj);
	mlx_mouse_hook(mlx_obj->win, mouse_hook, mlx_obj);
}

int	key_hook(int keycode, t_imx *mlx_obj)
{
	t_data	new_img;
	
	if (keycode == LEFT_ARROW)
		update_range(mlx_obj, 0);
	if (keycode == RIGHT_ARROW)
		update_range(mlx_obj, 1);
	if (keycode == DOWN_ARROW)
		update_range(mlx_obj, 2);
	if (keycode == UP_ARROW)
		update_range(mlx_obj, 3);
	if (keycode == ESC)
		return (1);
	fill_img(mlx_obj, mlx_obj->params);
	
	return (0);
}

int	mouse_hook(int keycode, t_imx *mlx_obj)
{
	printf("mouse hook is %i\n", keycode);
	(void)mlx_obj;
	return (0);
}

void	zoom(t_imx *mlx_obj, float scale)
{
	(void)mlx_obj;
	(void)scale;
	return ;
}
