/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 14:06:40 by vviterbo          #+#    #+#             */
/*   Updated: 2024/12/02 19:23:50 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

float	madelbrot(float cr, float ci, int nsteps);
char	**gen_map(char **map, int *dims, int nsteps, int (*f)(int, int, int));

float	madelbrot(float cr, float ci, int nsteps)
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
		r_temp = r0 * r0 - i0 * i0 + cr;
		i0 = 2 * r0 * i0 + ci;
		r0 = r_temp;
		i++;
	}
	if (i == nsteps)
		return (1);
	return (cbrt(i / (float)nsteps));
}

char	**gen_map(char **map, int *dims, int nsteps, int (*f)(int, int, int))
{
	int	i;
	int	j;

	i = dims[0];
	while (i < dims[2])
	{
		map[i] = ft_calloc(dims[3] - dims[1], sizeof(int));
		j = dims[1];
		while (j < dims[3])
		{
			map[i][j] = f(i, j, nsteps);
			j++;
		}
		i++;
	}
	return (map);
}
