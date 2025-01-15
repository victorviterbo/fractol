/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 18:56:06 by vviterbo          #+#    #+#             */
/*   Updated: 2025/01/15 16:25:51 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	update_img(t_imx *data, t_params *params);

int	main(int argc, char *argv[])
{
	t_imx		*data;

	arg_check(argc, argv);
	data = ft_calloc(1, sizeof(t_imx));
	data->mlx = mlx_init();
	data->params = parse_params(argc, argv);
	data->curr_img = ft_calloc(1, sizeof(t_data));
	data->curr_img->img = mlx_new_image(data->mlx, data->params->window_size.x,
			data->params->window_size.y);
	data->win = mlx_new_window(data->mlx, data->params->window_size.x,
			data->params->window_size.y, "fractol");
	update_img(data, data->params);
	mlx_put_image_to_window(data->mlx, data->win, data->curr_img->img, 0, 0);
	set_hooks(data);
	mlx_loop(data->mlx);
	free_all(data);
	return (0);
}

void	update_img(t_imx *data, t_params *params)
{
	t_data	*img;
	t_coor	current;

	ft_printf("Loading image... ");
	img = data->curr_img;
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	current.x = 0;
	while (current.x < params->window_size.x)
	{
		current.y = 0;
		while (current.y < params->window_size.y)
		{
			set_pixel(current, data, params);
			current.y++;
		}
		current.x++;
	}
	ft_printf("Done !\n");
	return ;
}
