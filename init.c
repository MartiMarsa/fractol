/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:45:19 by mmarsa-s          #+#    #+#             */
/*   Updated: 2024/01/30 13:45:21 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
 * Establecer la conexion con el entorno grafico
 * inicializar la ventana
 * 
*/

static void	alloc_error(void)
{
	perror("Memory allocation fail");
	exit(EXIT_FAILURE);
}

void	init_data(t_fractal *fractal)
{
	fractal->mlx_con = mlx_init();
	if (NULL == fractal->mlx_con)
		alloc_error(); // TO-DO
	fractal->mlx_win = mlx_new_window(fractal->mlx_con, WIDTH, HEIGHT, fractal->name);
	if (NULL == fractal->mlx_win)
	{
		mlx_destroy_window(fractal->mlx_con, fractal->mlx_win);
		free(fractal->mlx_con);
		alloc_error();
	}
	fractal->img.img = mlx_new_image(fractal->mlx_con, WIDTH, HEIGHT);
	if (NULL == fractal->img.img)
	{
		mlx_destroy_image(fractal->mlx_con, fractal->mlx_win);
		mlx_destroy_window(fractal->mlx_con, fractal->mlx_win);
		free(fractal->mlx_con);
		alloc_error();
	}
	fractal->img.addr = mlx_get_data_addr(fractal->img.img, &fractal->img.bits_per_pixel,
											&fractal->img.line_length, &fractal->img.endian);
	//events_init(fractal); TO-DO
	//data_init(fractal)l; To-do

}