/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:53:22 by mmarsa-s          #+#    #+#             */
/*   Updated: 2024/02/01 15:53:24 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <string.h>

void	mandelbrot(t_fractal *fractal)
{
	double	max_limit;

	max_limit = 2.0;
	fractal->name = "Mandelbrot";
	fractal->type = 1;
	fractal->maxiter = 100;
	fractal->color = 8;
	fractal->ciao = 4.0;
	fractal->lim.cr = 0;
	fractal->lim.cim = 0;
	fractal->lim.xmin = fmin(fractal->lim.xmin, -max_limit);
	fractal->lim.xmax = fmax(fractal->lim.xmax, max_limit);
	fractal->lim.ymin = fmin(fractal->lim.ymin, -max_limit);
	fractal->lim.ymax = fmax(fractal->lim.ymax, max_limit);
}

void	draw_mandelbrot(t_fractal *fractal)
{
	double	x;
	double	y;
	double	temp;

	x = 0;
	y = 0;
	fractal->iter = -1;
	while ((x * x + y * y) <= fractal->ciao
		&& ++fractal->iter < fractal->maxiter)
	{
		temp = x * x - y * y + fractal->x;
		y = 2 * x * y + fractal->y;
		x = temp;
	}
}
