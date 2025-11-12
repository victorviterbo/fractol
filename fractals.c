/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 14:06:40 by vviterbo          #+#    #+#             */
/*   Updated: 2025/11/12 16:54:09 by victorviter      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	madelbrot(t_coor c0, int nsteps);
double	julia(t_coor xy, t_coor c0, int nsteps);
double	burning_ship(t_coor xy, int nsteps);

double	madelbrot(t_coor c0, int nsteps)
{
	double	i;
	t_coor	xy;
	double	r_temp;

	i = 0;
	xy.x = 0;
	xy.y = 0;
	while (i < nsteps && pow(xy.x, 2) + pow(xy.y, 2) <= 4)
	{
		r_temp = xy.x * xy.x - xy.y * xy.y + c0.x;
		xy.y = 2 * xy.x * xy.y + c0.y;
		xy.x = r_temp;
		i++;
	}
	if (i == nsteps)
		return (1.0);
	i = i + 4 / (pow(xy.x, 2) + pow(xy.y, 2));
	return (i / (double)nsteps);
}

double	julia(t_coor xy, t_coor c, int nsteps)
{
	double	i;
	double	r_temp;

	i = 0;
	while (i < nsteps && pow(xy.x, 2) + pow(xy.y, 2) < 4)
	{
		r_temp = xy.x * xy.x - xy.y * xy.y + c.x;
		xy.y = 2 * xy.x * xy.y + c.y;
		xy.x = r_temp;
		i++;
	}
	if (i == nsteps)
		return (1.0);
	i = i + 4 / (pow(xy.x, 2) + pow(xy.y, 2));
	return (i / (double)nsteps);
}

double	burning_ship(t_coor xy, int nsteps)
{
	double	i;
	t_coor	xy0;
	double	r_temp;

	i = 0;
	xy0.x = xy.x;
	xy0.y = xy.y;
	while (i < nsteps && pow(xy.x, 2) + pow(xy.y, 2) < 4)
	{
		r_temp = xy.x * xy.x - xy.y * xy.y + xy0.x;
		xy.y = ft_abs(2 * xy.x * xy.y) + xy0.y;
		xy.x = r_temp;
		i++;
	}
	if (i == nsteps)
		return (1.0);
	i = i + 4 / (pow(xy.x, 2) + pow(xy.y, 2));
	return (i / (double)nsteps);
}
