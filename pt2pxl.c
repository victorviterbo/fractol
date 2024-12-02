/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pt2pxl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 19:24:42 by vviterbo          #+#    #+#             */
/*   Updated: 2024/12/03 00:26:17 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_coor	pxl2pt(t_coor xy, t_coor xymin, t_coor xymax, t_coor size);

t_coor	pxl2pt(t_coor xy, t_coor xymin, t_coor xymax, t_coor size)
{
	xy.x = xy.x * (xymax.x - xymin.x) / size.x;
	xy.y = xy.y * (xymax.y - xymin.y) / size.y;
	xy.x = xy.x + xymin.x;
	xy.y = xy.y + xymin.y;
	printf("x = %f, y = %f\n", xy.x, xy.y);
	return (xy);
}
