/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorviterbo <victorviterbo@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:10:02 by vviterbo          #+#    #+#             */
/*   Updated: 2025/11/12 16:08:42 by victorviter      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_coor		scale_vector(t_coor base, t_coor tip, float scale);
t_coor		pxl2pt(t_coor xy, t_params *params);
t_coor		pt2pxl(t_coor xy, t_params *params);
char		*ft_str_upper(char *str);
int			free_all(t_imx *imx);
int			print_params(t_imx *imx);

t_coor	scale_vector(t_coor base, t_coor tip, float scale)
{
	t_coor	new_vector;

	new_vector.x = (tip.x - base.x) * (double)scale + base.x;
	new_vector.y = (tip.y - base.y) * (double)scale + base.y;
	return (new_vector);
}

t_coor	pxl2pt(t_coor xy, t_params *params)
{
	xy.x = xy.x * (params->max.x - params->min.x)
		/ (double)params->window_size.x;
	xy.y = xy.y * (params->max.y - params->min.y)
		/ (double)params->window_size.y;
	xy.x = xy.x + params->min.x;
	xy.y = xy.y + params->min.y;
	return (xy);
}

t_coor	pt2pxl(t_coor xy, t_params *params)
{
	xy.x = xy.x - params->min.x;
	xy.y = xy.y - params->min.y;
	xy.x = xy.x * (double)params->window_size.x
		/ (params->max.x - params->min.x);
	xy.y = xy.y * (double)params->window_size.y
		/ (params->max.y - params->min.y);
	return (xy);
}

char	*ft_str_upper(char *str)
{
	size_t	i;

	i = 0;
	while (*(str + i))
	{
		*(str + i) = ft_toupper(*(str + i));
		i++;
	}
	return (str);
}

int	free_all(t_imx *imx)
{
	mlx_destroy_window(imx->mlx, imx->win);
	mlx_destroy_image(imx->mlx, imx->curr_img->img);
	free(imx->curr_img);
	free(imx->params);
	free(imx);
	exit(0);
}

int	print_params(t_imx *imx)
{
	printf("=============  DISPLAY INFO  =============\n");
	if (imx->params->ft == MANDELBROT)
		printf("Fractal : MANDELBROT\n");
	if (imx->params->ft == JULIA)
		printf("Fractal : JULIA\n");
	if (imx->params->ft == BURNING_SHIP)
		printf("Fractal : BURNING_SHIP\n");
	printf("number of steps = %i\n", imx->params->nsteps);
	printf("window size = [%i, %i]\n", (int)imx->params->window_size.x, (int)imx->params->window_size.y);
	printf("display min = %f + i%f\n", imx->params->min.x, imx->params->min.y);
	printf("display max = %f + i%f\n", imx->params->max.x, imx->params->max.y);
	if (imx->params->ft == JULIA)
		printf("c0 = %f + i%f\n", imx->params->c0.x, imx->params->c0.y);
	printf("coloring scheme: %i\n", imx->params->coloring_scheme);
	printf("\n./fractol ");
	if (imx->params->ft == MANDELBROT)
		printf("MANDELBROT ");
	if (imx->params->ft == JULIA)
		printf("JULIA ");
	if (imx->params->ft == BURNING_SHIP)
		printf("BURNING_SHIP ");
	printf("%i %i %i %f %f %f %f ", imx->params->nsteps, (int)imx->params->window_size.x,
		(int)imx->params->window_size.y, imx->params->min.x, imx->params->min.y,
		imx->params->max.x, imx->params->max.y);
	if (imx->params->ft == JULIA)
		printf("%f %f %i\n", imx->params->c0.x, imx->params->c0.y, imx->params->coloring_scheme);
	else
		printf("%i\n", imx->params->coloring_scheme);
	printf("==========================================\n");
	return (0);
}