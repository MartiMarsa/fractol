/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 19:04:12 by mmarsa-s          #+#    #+#             */
/*   Updated: 2024/01/26 19:04:13 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <string.h>



static void	parsero(int argc, char **argv, t_fractal *fractal)
{
	t_lim	lim;

	ft_memset(&lim, 0, sizeof(t_lim));
	fractal->lim = lim;
	if (argc == 4 && !ft_strncmp(argv[1], "julia", 5) && !argv[1][5])
		julia(fractal, argv);
	else if (argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10) && !argv[1][10])
		mandelbrot(fractal);
	else if (argc == 2 && !ft_strncmp(argv[1], "burning_ship", 12) && !argv[1][12])
		burning_shit(fractal);
	else
	{
		ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	parsero(argc, argv, &fractal);
	init_data(&fractal);
	events_init(&fractal);
	mlx_loop(fractal.mlx_con);

	return (0);
}

//HAY PROBLEMAS EN EL PARSING, EN ATODBL DE JULIA, 
//EN LA RENDERIZACION CON TRIPLE BUFFER Y NO SE MUESTRA UNA MIERDA EN PANTALLA