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
static void	my_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static int	my_pixel_get(t_img *img, int x, int y)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	return (*(int *)pixel);
}

static void	imgcopy(t_img dst, t_img src, int x, int y)
{
	int i;
	int j;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			my_pixel_put(&dst, x + i, y + j, my_pixel_get(&src, i, j));
			j++;
		}
		i++;
	}
}

void	render_fractal(t_fractal *fractal)
{
	int			x;
	int			y;
	t_img		ptr_img;

	x = -1;
	while (++x < WIDTH)
	{	
		fractal->x = scale(x, fractal->lim.xmin, fractal->lim.xmax, WIDTH);
		y = -1;
		while (++y < HEIGHT)
		{
			fractal->y = scale(x, fractal->lim.ymin, fractal->lim.ymax, HEIGHT);
			if (fractal->type == 1)
				draw_mandelbrot(fractal);
			//else if (fractal->type == 2)
			//	draw_julia(fractal);
			else
				draw_shit(fractal);
			my_pixel_put(&ptr_img, x, y, LIME_SHOCK); // podemos hacer una funcion para el color PROBLEMAS GRAVES
		}
	}
	imgcopy(fractal->img, ptr_img, x, y);
	mlx_put_image_to_window(fractal->mlx_con, fractal->mlx_win, &fractal->img, 0, 0);
}