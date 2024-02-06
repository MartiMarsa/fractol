/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:53:48 by mmarsa-s          #+#    #+#             */
/*   Updated: 2024/02/01 15:53:50 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	burning_shit(t_fractal *fractal)
{
	double	max_limit;

	max_limit = 2.0;
	fractal->name = "Burning_ship";
	fractal->type = 3;
	fractal->maxiter = 100;
	fractal->color = 2;
	fractal->ciao = 5.0;
	fractal->lim.xmin = fmin(fractal->lim.xmin, -max_limit);
	fractal->lim.xmax = fmax(fractal->lim.xmax, max_limit);
	fractal->lim.ymin = fmin(fractal->lim.ymin, -max_limit);
	fractal->lim.ymax = fmax(fractal->lim.ymax, max_limit);
	fractal->lim.cr = 0;
	fractal->lim.cim = 0;
}

void	draw_shit(t_fractal *fractal)
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
		y = fabs(2 * x * y) + fractal->y;
		x = temp;
	}
}
