/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 13:55:42 by vviterbo          #+#    #+#             */
/*   Updated: 2024/12/02 14:54:34 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h> 
# include "minilibx_mms_20191025_beta/mlx.h"
# include "libft/libft.h"

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

int	madelbrot(int cr, int ci, int nsteps);
int	**gen_map(char **map, int *dims, int nsteps, int (*f)(int, int, int));

#endif