/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 13:55:42 by vviterbo          #+#    #+#             */
/*   Updated: 2024/12/03 18:05:54 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h> 
# include "minilibx/mlx.h"
# include "libft/libft.h"







#include <stdio.h>







# define ARROW_SCALE 0.1
# define ZOOM_SCALE 0.8

# define LEFT_ARROW 123
# define RIGHT_ARROW 124
# define UP_ARROW 126
# define DOWN_ARROW 125
# define ESC 53
# define LEFT_CLICK 1
# define RIGHT_CLICK 2
# define ZOOM_IN 1//4
# define ZOOM_OUT 2//5

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
	float	x;
	float	y;
}	t_coor;

typedef struct	s_params {
	t_coor	window_size;
	t_coor	min;
	t_coor	max;
	int		nsteps;
	int		ft;
}	t_params;

typedef struct	s_imx {
	void		*mlx;
	void		*win;
	t_params	*params;
	t_data		*curr_img;
	t_data		*next_img;
}	t_imx;

//main.c
void		img_data_fill(t_data *data, int x, int y, float color);
float		map_colors(float color);
void		fill_img(t_imx *mlx_obj, t_params *params);
t_params	*parse_params(char *argv[]);
//fractals.c
float		madelbrot(t_coor xy, int nsteps);
//hooks.c
void	set_hooks(t_imx *mlx_obj);
int		key_hook(int keycode, t_imx *mlx_obj);
int		mouse_hook(int mousecode, int x, int y, t_imx *mlx_obj);
//utils.c
t_coor	scale_vector(t_coor base, t_coor tip, float scale);
t_coor	pxl2pt(t_coor xy, t_params *params);
void	update_range_shift(t_imx *mlx_obj, int dir);
int		close_free_all(t_imx *mlx_obj);
void	update_range_zoom(t_imx *mlx_obj, int mousecode, t_coor mouse);

#endif