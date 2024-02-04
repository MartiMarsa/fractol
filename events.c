/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:44:08 by mmarsa-s          #+#    #+#             */
/*   Updated: 2024/02/02 16:44:10 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zooming(int key, double x, double y, t_fractal *f)
{
	double	i;
	double	j;

	i = f->lim.xmax - f->lim.xmin;
	j = f->lim.ymax - f->lim.ymin;

	if (key == ZOOM_IN)
	{
		f->lim.xmax += (i * ZOOM - i) * x;
		f->lim.xmin -= (i * ZOOM - i) * (1 - x);
		f->lim.ymin -= (j * ZOOM - j) * y;
		f->lim.ymax += (j * ZOOM - j) * (1 - y);
	}
	if (key == ZOOM_OUT)
	{
		f->lim.xmin -= (i / ZOOM - i) * x;
		f->lim.xmax += (i / ZOOM - i) * (1 - x);
		f->lim.ymin -= (j / ZOOM - j) * y;
		f->lim.ymax += (j / ZOOM - j) * (1 - y);
	}
}


void	moving(int key, t_fractal *f)
{
	double	x;
	double	y;

	x = f->lim.xmax - f->lim.xmin;
	y = f->lim.ymax - f->lim.ymin;

	if (key == UP)
	{
		f->lim.xmin += x * MOVE;
		f->lim.xmax += x * MOVE;
	}
	if (key == DOWN)
	{
		f->lim.xmin -= x * MOVE;
		f->lim.xmax -= x * MOVE;
	}
	if (key == LEFT)
	{
		f->lim.ymin += y * MOVE;
		f->lim.ymax += y * MOVE;
	}
	if (key == RIGHT)
	{
		f->lim.ymin -= y * MOVE;
		f->lim.ymax -= y * MOVE;
	}
}
