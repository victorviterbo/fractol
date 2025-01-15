/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviterbo <vviterbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 11:14:11 by vviterbo          #+#    #+#             */
/*   Updated: 2025/01/15 16:26:30 by vviterbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	arg_check(int argc, char *argv[]);
void	check_fract(int argc, char *arg_fract);

void	arg_check(int argc, char *argv[])
{
	int	i;

	i = 2;
	if (argc == 1)
		print_help_exit();
	else
		check_fract(argc, argv[1]);
	while (argv[i])
	{
		if (!ft_isfloat(argv[i]))
		{
			ft_printf("\nInvalid arguments, exiting\n\n", argc);
			print_help_exit();
		}
		i++;
	}
	return ;
}

void	check_fract(int argc, char *arg_fract)
{
	if ((ft_strncmp(ft_str_upper(arg_fract), "MANDELBROT",
				ft_strlen(arg_fract)) == 0) && argc != 2 && argc != 9)
	{
		ft_printf("\nWrong number of argument for Mandelbrot, exiting\n");
		print_help_exit();
	}
	else if ((ft_strncmp(ft_str_upper(arg_fract), "JULIA",
				ft_strlen(arg_fract)) == 0) && argc != 2 && argc != 11)
	{
		ft_printf("\nWrong number of argument for Julia, exiting\n");
		print_help_exit();
	}
	else if ((ft_strncmp(ft_str_upper(arg_fract), "BURNING_SHIP",
				ft_strlen(arg_fract)) == 0) && argc != 2 && argc != 9)
	{
		ft_printf("\nWrong number of argument for Burning Ship, exiting\n");
		print_help_exit();
	}
	else
	{
		ft_printf("\nFractal type not recogonized, exiting\n");
		print_help_exit();
	}
	return ;
}
