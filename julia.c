/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:53:37 by mmarsa-s          #+#    #+#             */
/*   Updated: 2024/02/01 15:53:38 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*static double	atodbl(char *str)
{
	double	result;
	int	sign;

	result = 0.0;
	sign = 1;
	if (!str)
		return (0);
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9' && *str)
	{
			result = result * 10 + (*str++ - '0');
	}
	return (result * sign);
}*/

void	julia(t_fractal *fractal, char **argv)
{
	double	max_limit;

	max_limit = 2.0;
	fractal->name = "Julia";
	fractal->type = 2;
	fractal->maxiter = 100;
	fractal->color = 1;
	fractal->ciao = 15.0;
	fractal->lim.xmin = fmin(fractal->lim.xmin, -max_limit);
	fractal->lim.xmax = fmax(fractal->lim.xmax, max_limit);
	fractal->lim.ymin = fmin(fractal->lim.ymin, -max_limit);
	fractal->lim.ymax = fmax(fractal->lim.ymax, max_limit);
	fractal->lim.cr = atof(argv[2]);
	fractal->lim.cim = atof(argv[3]);
}

void	draw_julia(t_fractal *fractal)
{
	double	x;
	double	y;
	double	temp;

	x = fractal->x;
	y = fractal->y;
	fractal->iter = -1;
	while ((x * x + y * y) <= fractal->ciao
		&& ++fractal->iter < fractal->maxiter)
	{
		temp = x * x - y * y + fractal->lim.cr;
		y = 2 * x * y + fractal->lim.cim;
		x = temp;
	}
}
