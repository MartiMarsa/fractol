/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 19:18:23 by mmarsa-s          #+#    #+#             */
/*   Updated: 2024/01/26 19:18:27 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// usamos esta funcion para escalar los numeros complejos a los pixeles de la ventana
double scale(double unscaledNum, double minAllowed, double maxAllowed, double max)
{
	return ((maxAllowed - minAllowed) * (unscaledNum) / max + minAllowed);
}

void	set_buffer(t_img *buffer, t_fractal fractal)
{
	buffer->img = mlx_new_image(fractal.mlx_con, WIDTH, HEIGHT);
	buffer->addr = mlx_get_data_addr(&buffer, &buffer->bits_per_pixel, &buffer->line_length, &buffer->endian);
	buffer->height = HEIGHT;
	buffer->width = WIDTH;
}

int	ft_color(t_fractal	*fractal)
{
	if (fractal->iter == 100)
		return (0x000000);
	else// if (fractal->type == 1)
	{
		return (fractal->color * fractal->iter << 16 | fractal->color << 8 | fractal->iter);
	}
}