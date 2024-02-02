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

/*void	zooming(int key, int x, int y, t_fractal *f)
{

}*/

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
}





