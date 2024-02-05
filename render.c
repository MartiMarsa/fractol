/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:40:51 by mmarsa-s          #+#    #+#             */
/*   Updated: 2024/01/30 15:40:53 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// necesitas una funcion que itera los pixeles y se los va a pasar a otra que los tome.
//
// hay que escalar las coordenadas del fractal al tamaño de la ventana.
//
// usamos funciones que usen aritmetica de vectores para operar con numeros complejos.
//
// renderizaremos los valores que no escapan al infinito. 

// funcion que recibe un color y una posicion
static void	my_pixel_put(t_fractal *f, int x, int y, int color)
{
	char	*dst;
	
	dst = f->img.addr + (y * f->img.line_length + x * (f->img.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

/*static unsigned int	my_pixel_get(t_img *img, int x, int y)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	return (*(unsigned int *)pixel);
}

void	imgcopy(t_img dst, t_img src, int x, int y)
{
	int i;
	int j;

	i = 0;
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
			my_pixel_put(&dst, x + j, y + i, my_pixel_get(&src, j, i));
			j++;
		}
		i++;
	}
}*/

int	render_fractal(t_fractal *fractal)
{
	int			x;
	int			y;

	int i = 0;
	y = -1;
	while (++y < HEIGHT)
	{	
		fractal->y = scale(y, fractal->lim.xmin, fractal->lim.xmax, WIDTH);
		x = -1;
		while (++x < WIDTH)
		{
			fractal->x = scale(x, fractal->lim.ymin, fractal->lim.ymax, HEIGHT);
			if (fractal->type == 1)
				i = draw_mandelbrot(fractal);
			else if (fractal->type == 2)
				i = draw_julia(fractal);
			else
				i = draw_shit(fractal);
			if (i < fractal->iterations)
				my_pixel_put(fractal, x, y, PSYCHEDELIC_PURPLE);
			else
				my_pixel_put(fractal, x, y, WHITE);
		}
	}
	mlx_put_image_to_window(fractal->mlx_con, fractal->mlx_win, fractal->img.img, 0, 0);
	return 0;
}