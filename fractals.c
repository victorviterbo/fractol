/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 14:06:40 by vviterbo          #+#    #+#             */
/*   Updated: 2024/12/05 20:10:18 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	madelbrot(t_coor xy, int nsteps);
double	julia(t_coor xy, t_coor c, int nsteps);

double	madelbrot(t_coor xy, int nsteps)
{
	double	i;
	double	r0;
	double	i0;
	double	r_temp;

	i = 0;
	r0 = 0;
	i0 = 0;
	while (i < nsteps && hypot(r0, i0) <= 2)
	{
		r_temp = r0 * r0 - i0 * i0 + xy.x;
		i0 = 2 * r0 * i0 + xy.y;
		r0 = r_temp;
		i++;
	}
	if (i == nsteps)
		return (1.0);
	i = i + hypot(r0, i0) / 2;
	return (sqrt(i / (double)nsteps));
}

double	julia(t_coor xy, t_coor c, int nsteps)
{
	double	i;
	double	r_temp;

	i = 0;
	while (i < nsteps && xy.x * xy.x + xy.y * xy.y < 4)
	{
		r_temp = xy.x * xy.x - xy.y * xy.y + c.x;
		xy.y = 2 * xy.x * xy.y + c.y;
		xy.x = r_temp;
		i++;
	}
	if (i == nsteps)
		return (1);
	return (i / (double)nsteps);
}
