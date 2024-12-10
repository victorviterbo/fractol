/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 13:39:09 by vviterbo          #+#    #+#             */
/*   Updated: 2024/12/10 13:36:45 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_params	*parse_params(int argc, char *argv[]);
t_params	*set_params_mandelbrot(t_params *params, int argc, char *argv[]);
t_params	*set_params_julia(t_params *params, int argc, char *argv[]);
t_params	*set_params_burning_ship(t_params *params, int argc, char *argv[]);
void		print_help();

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
	params->window_size.x = 400;
	params->min.x = -2;
	params->min.y = -1;
	params->max.x = 1;
	params->max.y = 1;
	if (ft_strncmp(argv[1], "MANDELBROT", ft_max(ft_strlen(argv[1]), 11)) == 0)
		return (set_params_mandelbrot(params, argc, argv));
	else if (ft_strncmp(argv[1], "JULIA", ft_max(ft_strlen(argv[1]), 6)) == 0)
		return (set_params_julia(params, argc, argv));
	else if (ft_strncmp(argv[1], "BURNING_SHIP",
			ft_max(ft_strlen(argv[1]), 13)) == 0)
		return (set_params_burning_ship(params, argc, argv));
	return (params);
}

t_params	*set_params_mandelbrot(t_params *params, int argc, char *argv[])
{
	params->ft = MANDELBROT;
	if (argc == 2)
		return (params);
	params->nsteps = ft_atoi(argv[2]);
	params->window_size.x = ft_atoi(argv[3]);
	params->window_size.y = ft_atoi(argv[4]);
	params->min.x = ft_atoi(argv[5]);
	params->min.y = ft_atoi(argv[6]);
	params->max.x = ft_atoi(argv[7]);
	params->max.y = ft_atoi(argv[8]);
	return (params);
}

t_params	*set_params_julia(t_params *params, int argc, char *argv[])
{
	params->ft = JULIA;
	if (argc == 2)
		return (params);
	params->nsteps = ft_atoi(argv[2]);
	params->window_size.x = ft_atoi(argv[3]);
	params->window_size.y = ft_atoi(argv[4]);
	params->min.x = ft_atoi(argv[5]);
	params->min.y = ft_atoi(argv[6]);
	params->max.x = ft_atoi(argv[7]);
	params->max.y = ft_atoi(argv[8]);
	params->c0.x = (double)ft_atof(argv[9]);
	params->c0.y = (double)ft_atof(argv[10]);
	return (params);
}

t_params	*set_params_burning_ship(t_params *params, int argc, char *argv[])
{
	params->ft = BURNING_SHIP;
	ft_printf("params->ft = %i\n", params->ft);
	if (argc < 3)
		return (params);
	params->nsteps = ft_atoi(argv[2]);
	ft_printf("params->nsteps = %i\n", params->nsteps);
	params->window_size.x = ft_atoi(argv[3]);
	params->window_size.y = ft_atoi(argv[4]);
	ft_printf("params->nsteps = %f %f\n", params->window_size.x, params->window_size.y);
	params->min.x = ft_atoi(argv[5]);
	params->min.y = ft_atoi(argv[6]);
	ft_printf("params->min = %f %f\n", params->min.x, params->min.y);
	params->max.x = ft_atoi(argv[7]);
	params->max.y = ft_atoi(argv[8]);
	ft_printf("params->max = %f %f\n", params->max.x, params->max.y);
	return (params);
}

void	print_help(void)
{
	ft_printf("Please provide input:\n");
	ft_printf("./fractol FT [nsteps winx winy re_min im_min ");
	ft_printf("re_max im_max [re_c0 im_c0]]\n");
	ft_printf("Where\n");
	ft_printf("FT is the fractal to display (available MANDELBROT, ");
	ft_printf("JULIA, BURNING_SHIP)\n");
	ft_printf("winx winy : x and y size of window (in pixels)\n");
	ft_printf("re_min im_min :");
	ft_printf(" real and imaginary part of the bottom left corner\n");
	ft_printf("re_max im_max : ");
	ft_printf("real and imaginary part of the top right corner\n");
	ft_printf("re_max im_max : ");
	ft_printf("real and imaginary part of the top right corner\n");
	ft_printf("c0x c0y : ");
	ft_printf("With Julia fractal only, the real and imaginary part ");
	ft_printf("of the starting point\n");
	exit(0);
}
