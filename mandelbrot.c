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

void	mandelbrot(t_fractal *fractal)
{
	fractal->type = 1;
	fractal->iterations = 100;
	fractal->ciao = 4.0;
	fractal->lim.ymin = 2;
	fractal->lim.ymax = -2;
	fractal->lim.xmin = 2;
	fractal->lim.xmax = -2;
	fractal->lim.cr = 0;
	fractal->lim.cim = 0;
}

void	draw_mandelbrot(t_fractal *fractal)
{
	double	x;
	double	y;
	double	temp;
	int		i;

	x = 0;
	y = 0;
	i = 0;
	while ((x * x + y * y) <= fractal->ciao && ++i < fractal->iterations)
	{
		temp = x * x - y * y + fractal->x;
		y = 2 * x * y + fractal->y;
		x = temp;
	}
}
