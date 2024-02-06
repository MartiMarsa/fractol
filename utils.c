/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 19:18:23 by mmarsa-s          #+#    #+#             */
/*   Updated: 2024/02/05 17:40:58 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// usamos esta funcion para escalar los numeros 
// complejos a los pixeles de la ventana
double	scale(double unscaledNum, double minAllowed,
				double maxAllowed, double max)
{
	return ((maxAllowed - minAllowed) * (unscaledNum) / max + minAllowed);
}

int	ft_color(t_fractal	*fractal)
{
	fractal->base = BLACK;
	if (fractal->iter == 100)
		return (fractal->base);
	else if (fractal->type == 1)
		return (fractal->color * fractal->iter << 16
			| fractal->color << 8 | fractal->iter);
	else if (fractal->type == 2)
		return (150 * fractal->color * fractal->iter << 16
			| fractal->color << 8 | fractal->iter);
	else
		return (234 * fractal->iter << 16 | fractal->color
			* fractal->iter << 8 | fractal->color);
}

void	my_pixel_put(t_fractal *f, int x, int y, int color)
{
	char	*dst;

	dst = f->img.addr + (y * f->img.line_length + x
			* (f->img.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
