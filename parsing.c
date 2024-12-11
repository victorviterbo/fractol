/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 13:39:09 by vviterbo          #+#    #+#             */
/*   Updated: 2024/12/10 15:50:34 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_params	*parse_params(int argc, char *argv[]);
t_params	*set_params_mandelbrot(t_params *params, int argc, char *argv[]);
t_params	*set_params_julia(t_params *params, int argc, char *argv[]);
t_params	*set_params_burning_ship(t_params *params, int argc, char *argv[]);
void		print_help(void);

t_params	*parse_params(int argc, char *argv[])
{
	t_params	*params;

	if (argc < 2)
		print_help();
	params = ft_calloc(1, sizeof(t_params));
	params->c0.x = -0.656;
	params->c0.x = -0.432;
	params->nsteps = 250;
	params->window_size.x = 600;
	params->window_size.y = 400;
	params->min.x = -2.0;
	params->min.y = -1.0;
	params->max.x = 1.0;
	params->max.y = 1.0;
	//if (argc > 1)
	//	argv[1] = ft_str_upper(argv[1]);
	if (ft_strncmp(ft_str_upper(argv[1]), "MANDELBROT", ft_max(ft_strlen(argv[1]), 11)) == 0)
		return (set_params_mandelbrot(params, argc, argv));
	else if (ft_strncmp(ft_str_upper(argv[1]), "JULIA", ft_max(ft_strlen(argv[1]), 6)) == 0)
		return (set_params_julia(params, argc, argv));
	else if (ft_strncmp(ft_str_upper(argv[1]), "BURNING_SHIP",
			ft_max(ft_strlen(argv[1]), 13)) == 0)
		return (set_params_burning_ship(params, argc, argv));
	exit(1);
}

t_params	*set_params_mandelbrot(t_params *params, int argc, char *argv[])
{
	params->ft = MANDELBROT;
	if (argc == 2)
		return (params);
	params->nsteps = ft_atoi(argv[2]);
	params->nsteps = ft_atoi(argv[2]);
	params->window_size = ft_initvec((double)ft_atof(argv[3]),
			(double)ft_atof(argv[4]), 0);
	params->min = ft_initvec((double)ft_atof(argv[5]), (double)ft_atof(argv[6]),
			0);
	params->max = ft_initvec((double)ft_atof(argv[7]), (double)ft_atof(argv[8]),
			0);
	return (params);
}

t_params	*set_params_julia(t_params *params, int argc, char *argv[])
{
	params->ft = JULIA;
	if (argc == 2)
		return (params);
	params->nsteps = ft_atoi(argv[2]);
	params->window_size = ft_initvec((double)ft_atof(argv[3]),
			(double)ft_atof(argv[4]), 0);
	params->min = ft_initvec((double)ft_atof(argv[5]), (double)ft_atof(argv[6]),
			0);
	params->max = ft_initvec((double)ft_atof(argv[7]), (double)ft_atof(argv[8]),
			0);
	params->c0 = ft_initvec((double)ft_atof(argv[9]), (double)ft_atof(argv[10]),
			0);
	return (params);
}

t_params	*set_params_burning_ship(t_params *params, int argc, char *argv[])
{
	params->ft = BURNING_SHIP;
	ft_printf("params->ft = %i\n", params->ft);
	if (argc < 3)
		return (params);
	params->nsteps = ft_atoi(argv[2]);
	params->window_size = ft_initvec((double)ft_atof(argv[3]),
			(double)ft_atof(argv[4]), 0);
	params->min = ft_initvec((double)ft_atof(argv[5]), (double)ft_atof(argv[6]),
			0);
	params->max = ft_initvec((double)ft_atof(argv[7]), (double)ft_atof(argv[8]),
			0);
	return (params);
}

void	print_help(void)
{
	ft_printf("Please provide input:\n");
	ft_printf("./fractol FT [nsteps winx winy re_min im_min ");
	ft_printf("re_max im_max [re_c0 im_c0]]\n");
	ft_printf("Where\n");
	ft_printf("- FT is the fractal to display (available MANDELBROT, ");
	ft_printf("JULIA, BURNING_SHIP)\n");
	ft_printf("- winx, winy : horizontal and vertical size");
	ft_printf(" of window (respectively, in pixels)\n");
	ft_printf("- re_min, im_min : real and imaginary part ");
	ft_printf("of the bottom left corner\n");
	ft_printf("- re_max, im_max : real and imaginary part ");
	ft_printf("of the top right corner\n");
	ft_printf("- c0x, c0y : ");
	ft_printf("With Julia fractal only, the real and imaginary part ");
	ft_printf("of the starting point\n");
	exit(0);
}
