/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 13:55:42 by vviterbo          #+#    #+#             */
/*   Updated: 2024/12/02 20:22:29 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h> 
# include "minilibx/mlx.h"
# include "libft/libft.h"




#include <stdio.h>






enum e_FRACTYPE {
	MANDELBROT,
	JULIA
};

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct	s_coor {
	double	x;
	double	y;
}	t_coor;

void	img_data_fill(t_data *data, int x, int y, float color);
float	madelbrot(float cr, float ci, int nsteps);
char	**gen_map(char **map, int *dims, int nsteps, int (*f)(int, int, int));
float	map_colors(float color);
t_coor	map_pixel(t_coor xy, t_coor xymin, t_coor xymax, t_coor size);

#endif