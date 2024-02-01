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
	fractal->type = 3;
	fractal->iterations = 100;
	fractal->ciao = 7.0;
	fractal->lim.ymin = 2;
	fractal->lim.ymax = -2;
	fractal->lim.xmin = 2;
	fractal->lim.xmax = -2;
	fractal->lim.cr = 0;
	fractal->lim.cim = 0;
}

void	draw_shit(t_fractal *fractal)
{
	double	x;
	double	y;
	double	temp;
    int     i;

	x = 0;
	y = 0;
    i = 0;
	i = -1;
	while ((x * x + y * y) <= fractal->ciao && ++i < fractal->iterations)
	{
		temp = x * x - y * y + fractal->x;
		y = fabs(2 * x * y) + fractal->y;
		x = temp;
	}
}