/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:10:02 by vviterbo          #+#    #+#             */
/*   Updated: 2024/12/11 14:42:23 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_coor		scale_vector(t_coor base, t_coor tip, float scale);
t_coor		pxl2pt(t_coor xy, t_params *params);
t_coor		pt2pxl(t_coor xy, t_params *params);
char		*ft_str_upper(char *str);
int			free_all(t_imx *data);

t_coor	scale_vector(t_coor base, t_coor tip, float scale)
{
	t_coor	new_vector;

	new_vector.x = (tip.x - base.x) * (double)scale + base.x;
	new_vector.y = (tip.y - base.y) * (double)scale + base.y;
	return (new_vector);
}

t_coor	pxl2pt(t_coor xy, t_params *params)
{
	xy.x = xy.x * (params->max.x - params->min.x)
		/ (double)params->window_size.x;
	xy.y = xy.y * (params->max.y - params->min.y)
		/ (double)params->window_size.y;
	xy.x = xy.x + params->min.x;
	xy.y = xy.y + params->min.y;
	return (xy);
}

t_coor	pt2pxl(t_coor xy, t_params *params)
{
	xy.x = xy.x - params->min.x;
	xy.y = xy.y - params->min.y;
	xy.x = xy.x * (double)params->window_size.x
		/ (params->max.x - params->min.x);
	xy.y = xy.y * (double)params->window_size.y
		/ (params->max.y - params->min.y);
	return (xy);
}

char	*ft_str_upper(char *str)
{
	size_t	i;

	i = 0;
	while (*(str + i))
	{
		*(str + i) = ft_toupper(*(str + i));
		i++;
	}
	return (str);
}

int	free_all(t_imx *data)
{
	mlx_destroy_image(data->mlx, data->curr_img->img);
	mlx_destroy_image(data->mlx, data->next_img->img);
	free(data->curr_img);
	free(data->next_img);
	free(data->params);
	exit(0);
}
