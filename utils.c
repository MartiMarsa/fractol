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

void	set_buffer(t_img *buffer, t_fractal fractal)
{
	buffer->img = mlx_new_image(fractal.mlx_con, WIDTH, HEIGHT);
	buffer->addr = mlx_get_data_addr(&buffer, &buffer->bits_per_pixel,
			&buffer->line_length, &buffer->endian);
	buffer->height = HEIGHT;
	buffer->width = WIDTH;
}

int	ft_color(t_fractal	*fractal)
{
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
