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
	else if (argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10)
		&& !argv[1][10])
		mandelbrot(fractal);
	else if (argc == 2 && !ft_strncmp(argv[1], "burning_ship", 12)
		&& !argv[1][12])
		burning_shit(fractal);
	else
	{
		ft_printf("\nError: Invalid command line arguments. Please use one ");
		ft_printf("of the following formats:\n\n1.For Mandelbrot set: ./");
		ft_printf("fractal mandelbrot\n\n2.For Julia set: ./fractal julia");
		ft_printf(" n1 n2\nwhere n1 and n2 are numeric values representing");
		ft_printf(" the complex constant.\n\n3. For Burning Ship set: ./");
		ft_printf("fractal burning_ship\n\nPlease provide the correct ");
		ft_printf("command line arguments and try again.\n\n");
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
