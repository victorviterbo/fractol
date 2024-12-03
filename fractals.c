/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 14:06:40 by vviterbo          #+#    #+#             */
/*   Updated: 2024/12/03 12:05:11 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

float	madelbrot(t_coor xy, int nsteps);

float	madelbrot(t_coor xy, int nsteps)
{
	float	i;
	float	r0;
	float	i0;
	float	r_temp;

	i = 0;
	r0 = 0;
	i0 = 0;
	while (i < nsteps && r0 * r0 + i0 * i0 < 4)
	{
		r_temp = r0 * r0 - i0 * i0 + xy.x;
		i0 = 2 * r0 * i0 + xy.y;
		r0 = r_temp;
		i++;
	}
	if (i == nsteps)
		return (1);
	return (cbrt(i / (float)nsteps));
}
