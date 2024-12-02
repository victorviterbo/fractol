/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pt2pixel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 19:24:42 by vviterbo          #+#    #+#             */
/*   Updated: 2024/12/02 20:22:22 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_coor	map_pixel(t_coor xy, t_coor xymin, t_coor xymax, t_coor size);

t_coor	map_pixel(t_coor xy, t_coor xymin, t_coor xymax, t_coor size)
{
	xy.x = xy.x - xymin.x;
	xy.y = xy.y - xymin.y;
	xy.x = xy.x * size.x / (xymax.x - xymax.x);
	xy.y = xy.y * size.y / (xymax.y - xymax.y);
	return (xy);
}
