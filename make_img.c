/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 15:23:58 by vviterbo          #+#    #+#             */
/*   Updated: 2024/11/26 18:42:53 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	make_img(int **map, void *mlx, int *dims, int ft);

void	make_img(int **map, void *mlx, int *dims, int ft)
{
	void	*img;
	char	*img_data;
	int		*pixelsize;
	int		*linesize;
	int		*endian;

	endian = ft_calloc(1, sizeof(int));
	pixelsize = ft_calloc(1, sizeof(int));
	linesize = ft_calloc(1, sizeof(int));
	img = mlx_new_image(mlx, dims[3] - dims[1], dims[2] - dims[0]);
	img_data = mlx_get_data_addr(img, pixelsize, linesize, endian);
	img_filldata(img_data, ft, dims);
}

void	img_filldata(void *img_data, )
