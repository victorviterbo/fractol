/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 14:06:40 by vviterbo          #+#    #+#             */
/*   Updated: 2024/11/26 19:01:10 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	madelbrot(int cr, int ci, int nsteps);
int	**gen_map(char **map, int *dims, int nsteps, int (*f)(int, int, int));

int	madelbrot(int cr, int ci, int nsteps)
{
	int	i;
	int	r0;
	int	i0;

	i = 0;
	r0 = 0;
	i0 = 0;
	while (i < nsteps && hypot(r0, i0) < 2)
	{
		r0 = r0 * r0 - i0 * i0 + cr;
		i0 = -2 * r0 * i0 + ci;
		i++;
	}
	return (i);
}

int	**gen_map(char **map, int *dims, int nsteps, int (*f)(int, int, int))
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
