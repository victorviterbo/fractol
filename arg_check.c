/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 11:14:11 by vviterbo          #+#    #+#             */
/*   Updated: 2025/11/12 14:31:53 by victorviter      ###   ########.fr       */
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
		if (!ft_isfloat(argv[i]) && ft_strcmp(argv[i], "")
			&& ft_strncmp(ft_str_upper(argv[8]), "AUTO", ft_strlen(argv[8])) != 0)
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
				ft_strlen(arg_fract)) == 0) && (argc == 2 || argc == 9 || argc == 10))
		return ;
	else if ((ft_strncmp(ft_str_upper(arg_fract), "JULIA",
				ft_strlen(arg_fract)) == 0) && (argc == 2 || argc == 11 || argc == 12))
		return ;
	else if ((ft_strncmp(ft_str_upper(arg_fract), "BURNING_SHIP",
				ft_strlen(arg_fract)) == 0) && (argc == 2 || argc == 9 || argc == 10))
		return ;
	else
	{
		ft_printf("\nWrong number of argument for Fractal ");
		ft_printf("or Fractal not recogonized. Exiting ...\n");
		print_help_exit();
	}
	return ;
}
