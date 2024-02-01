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



static void	set_fractal(t_fractal *fractal, char **argv)
{
	(void)argv;
	//if (!ft_strncmp(fractal->name, "julia", 5))
	//	julia(fractal, argv);
	if (!ft_strncmp(fractal->name, "mandelbrot", 10))
		mandelbrot(fractal);
	if (!ft_strncmp(fractal->name, "burning_ship", 12))
		burning_shit(fractal);
}

int	main(int argc, char **argv)
{
	t_fractal	fractal;
	(void)argc;

	/*if (!(argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 11) && !argv[1][11])
		|| !(argc == 4 && !ft_strncmp(argv[1], "julia", 5) && !argv[6])
		|| !(argc == 2 && !ft_strncmp(argv[1], "burning_ship", 12) && !argv[13]))
	{
		ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	else
	{*/
		fractal.name = argv[1];
		set_fractal(&fractal, argv);
		init_data(&fractal);
		render_fractal(&fractal);
		mlx_loop(fractal.mlx_con);
	//}
	return (0);
}

//HAY PROBLEMAS EN EL PARSING, EN ATODBL DE JULIA, 
//EN LA RENDERIZACION CON TRIPLE BUFFER Y NO SE MUESTRA UNA MIERDA EN PANTALLA