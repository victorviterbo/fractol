/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 13:55:42 by vviterbo          #+#    #+#             */
/*   Updated: 2025/01/20 19:38:44 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include "minilibx_opengl/mlx.h"
# include "libft/libft.h"

# define ARROW_SCALE 0.1
# define ZOOM_SCALE 0.9

# define MACOS 0
# define LINUX 1

# ifdef __linux__
#  define LEFT_ARROW 65363
#  define RIGHT_ARROW 65361
#  define UP_ARROW 65362
#  define DOWN_ARROW 65364
#  define ESC 65307
#  define LEFT_CLICK 1
#  define RIGHT_CLICK 3
#  define ZOOM_IN 4
#  define ZOOM_OUT 5
# elif defined __APPLE__
#  define LEFT_ARROW 123
#  define RIGHT_ARROW 124
#  define UP_ARROW 126
#  define DOWN_ARROW 125
#  define ESC 53
#  define LEFT_CLICK 1
#  define RIGHT_CLICK 2
#  define ZOOM_IN 4
#  define ZOOM_OUT 5

# endif

enum e_FRACTYPE {
	MANDELBROT,
	JULIA,
	BURNING_SHIP
};

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_params {
	t_coor	window_size;
	t_coor	min;
	t_coor	max;
	int		nsteps;
	int		ft;
	t_coor	c0;
}	t_params;

typedef struct s_imx {
	void		*mlx;
	void		*win;
	t_params	*params;
	t_data		*curr_img;
}	t_imx;

//fractol.c
t_imx	*ft_init_mlx(int argc, char *argv[]);
void	update_img(t_imx *imx, t_params *params);
//fractals.c
double		madelbrot(t_coor c0, int nsteps);
double		julia(t_coor xy, t_coor c0, int nsteps);
double		burning_ship(t_coor xy, int nsteps);
//hooks.c
void		set_hooks(t_imx *imx);
int			key_hook(int keycode, t_imx *imx);
int			mouse_hook(int mousecode, int x, int y, t_imx *imx);
//parsing.c
t_params	*parse_params(int argc, char *argv[]);
t_params	*set_params_mandelbrot(t_params *params, int argc, char *argv[]);
t_params	*set_params_julia(t_params *params, int argc, char *argv[]);
t_params	*set_params_burning_ship(t_params *params, int argc, char *argv[]);
void		print_help_exit(void);
//utils_img.c
int			free_all(t_imx *imx);
void		update_range_shift(t_imx *imx, int dir);
void		update_range_zoom(t_imx *imx, int mousecode, t_coor mouse);
void		set_pixel(t_coor pxl, t_imx *imx, t_params *params);
int			map_colors(double color);
//utils.c
t_coor		scale_vector(t_coor base, t_coor tip, float scale);
t_coor		pxl2pt(t_coor xy, t_params *params);
t_coor		pt2pxl(t_coor xy, t_params *params);
char		*ft_str_upper(char *str);
int			free_all(t_imx *imx);
//arg_check.c
void		arg_check(int argc, char *argv[]);
void		check_fract(int argc, char *arg_fract);

#endif