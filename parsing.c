/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 13:39:09 by vviterbo          #+#    #+#             */
/*   Updated: 2025/01/13 15:28:15 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_params	*parse_params(int argc, char *argv[]);
t_params	*set_params_mandelbrot(t_params *params, int argc, char *argv[]);
t_params	*set_params_julia(t_params *params, int argc, char *argv[]);
t_params	*set_params_burning_ship(t_params *params, int argc, char *argv[]);
void		print_help_exit(void);

t_params	*parse_params(int argc, char *argv[])
{
	t_params	*params;

	params = ft_calloc(1, sizeof(t_params));
	params->c0 = ft_initvec(-0.4, 0.6, 0);
	params->nsteps = 50;
	params->window_size = ft_initvec(600, 400, 0);
	params->min = ft_initvec(-2.0, -1, 0);
	params->max = ft_initvec(1.0, 1, 0);
	if (ft_strncmp(ft_str_upper(argv[1]), "MANDELBROT",
			ft_strlen(argv[1])) == 0)
		return (set_params_mandelbrot(params, argc, argv));
	else if (ft_strncmp(ft_str_upper(argv[1]), "JULIA",
			ft_strlen(argv[1])) == 0)
		return (set_params_julia(params, argc, argv));
	else if (ft_strncmp(ft_str_upper(argv[1]), "BURNING_SHIP",
			ft_strlen(argv[1])) == 0)
		return (set_params_burning_ship(params, argc, argv));
	print_help_exit();
	return (params);
}

t_params	*set_params_mandelbrot(t_params *params, int argc, char *argv[])
{
	if (argc != 2 && argc != 9)
	{
		ft_printf("\nIncorect number of arguments (%i != 9), exiting\n\n", argc);
		print_help_exit();
	}
	params->ft = MANDELBROT;
	if (argc == 2)
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

t_params	*set_params_julia(t_params *params, int argc, char *argv[])
{
	if (argc != 2 && argc != 11)
	{
		ft_printf("\nIncorect number of arguments (%i != 11), exiting\n\n", argc);
		print_help_exit();
	}
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
	if (argc != 2 && argc != 9)
	{
		ft_printf("\nIncorect number of arguments (%i != 9), exiting\n\n", argc);
		print_help_exit();
	}
	params->ft = BURNING_SHIP;
	if (argc == 2)
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

void	print_help_exit(void)
{
	ft_printf("Please provide correct input:\n");
	ft_printf("./fractol FT [nsteps winx winy re_min im_min ");
	ft_printf("re_max im_max [re_c0 im_c0]]\n");
	ft_printf("Where\n");
	ft_printf("- FT is the fractal to display (available MANDELBROT, ");
	ft_printf("JULIA, BURNING_SHIP), parameter is not case-sensitive\n");
	ft_printf("- nsteps is the number of iterations\n");
	ft_printf(" to be performed per pixel");
	ft_printf("- winx, winy : horizontal and vertical size");
	ft_printf(" of window (respectively, in pixels)\n");
	ft_printf("- re_min, im_min : real and imaginary part ");
	ft_printf("of the bottom left corner\n");
	ft_printf("- re_max, im_max : real and imaginary part ");
	ft_printf("of the top right corner\n");
	ft_printf("- c0x, c0y : ");
	ft_printf("With Julia fractal only, the real and imaginary part ");
	ft_printf("of the starting point\n");
	ft_printf("Defaults are [100 600 400 -2.0 -1.0 1 1 [-0.4, 0.6]]\n");
	exit(0);
}
