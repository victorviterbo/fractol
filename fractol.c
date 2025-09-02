/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 18:56:06 by vviterbo          #+#    #+#             */
/*   Updated: 2025/01/20 20:06:15 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_imx	*ft_init_mlx(int argc, char *argv[]);
void	update_img(t_imx *imx, t_params *params);

int	main(int argc, char *argv[])
{
	t_imx		*imx;

	arg_check(argc, argv);
	imx = ft_init_mlx(argc, argv);
	if (!imx)
		return (1);
	update_img(imx, imx->params);
	mlx_put_image_to_window(imx->mlx, imx->win, imx->curr_img->img, 0, 0);
	set_hooks(imx);
	mlx_loop(imx->mlx);
	free_all(imx);
	return (0);
}

t_imx	*ft_init_mlx(int argc, char *argv[])
{
	t_imx	*imx;

	imx = ft_calloc(1, sizeof(t_imx));
	if (!imx)
		return (NULL);
	imx->mlx = mlx_init();
	if (!imx->mlx)
		return (free(imx), NULL);
	imx->params = parse_params(argc, argv);
	if (!imx->params)
		return (free(imx->mlx), free(imx), NULL);
	imx->curr_img = ft_calloc(1, sizeof(t_data));
	if (!imx->curr_img)
		return (free(imx->params), free(imx->mlx), free(imx), NULL);
	imx->curr_img->img = mlx_new_image(imx->mlx, imx->params->window_size.x,
			imx->params->window_size.y);
	if (!imx->curr_img->img)
		return (free(imx->curr_img), free(imx->params), free(imx->mlx),
			free(imx), NULL);
	imx->win = mlx_new_window(imx->mlx, imx->params->window_size.x,
			imx->params->window_size.y, "fractol");
	if (!imx->win)
		return (free(imx->curr_img->img), free(imx->curr_img),
			free(imx->params), free(imx->mlx), free(imx), NULL);
	return (imx);
}

void	update_img(t_imx *imx, t_params *params)
{
	t_data	*img;
	t_coor	current;

	ft_printf("Loading image... ");
	img = imx->curr_img;
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	current.x = 0;
	while (current.x < params->window_size.x)
	{
		current.y = 0;
		while (current.y < params->window_size.y)
		{
			set_pixel(current, imx, params);
			current.y++;
		}
		current.x++;
	}
	ft_printf("Done !\n");
	return ;
}
