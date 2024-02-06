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

int	render_fractal(t_fractal *fractal)
{
	int			x;
	int			y;

	x = -1;
	while (++x < WIDTH)
	{
		fractal->x = scale(x, fractal->lim.xmin, fractal->lim.xmax, WIDTH);
		y = -1;
		while (++y < WIDTH)
		{
			fractal->y = scale(y, fractal->lim.ymin, fractal->lim.ymax, HEIGHT);
			if (fractal->type == 1)
				draw_mandelbrot(fractal);
			else if (fractal->type == 2)
				draw_julia(fractal);
			else
				draw_shit(fractal);
			my_pixel_put(fractal, x, y, ft_color(fractal));
		}
	}
	mlx_put_image_to_window(fractal->mlx_con, fractal->mlx_win,
		fractal->img.img, 0, 0);
	return (0);
}

static int	cleanshit(t_fractal *fractal)
{
	if (fractal && fractal->mlx_win)
		mlx_destroy_window(fractal->mlx_con, fractal->mlx_win);
	exit (1);
}

/*
 * Establecer la conexion con el entorno grafico
 * inicializar la ventana
 * 
*/
static void	init_data(t_fractal *fractal)
{
	t_img	img;

	fractal->mlx_con = NULL;
	fractal->mlx_win = NULL;
	fractal->mlx_con = mlx_init();
	if (NULL == fractal->mlx_con)
		exit(1);
	fractal->mlx_win = mlx_new_window(fractal->mlx_con, WIDTH,
			HEIGHT, fractal->name);
	if (NULL == fractal->mlx_win)
	{
		free(fractal->mlx_con);
		exit (1);
	}
	ft_memset(&img, 0, sizeof(t_img));
	fractal->img = img;
	fractal->img.img = mlx_new_image(fractal->mlx_con, WIDTH, HEIGHT);
	if (NULL == fractal->img.img)
		exit(cleanshit(fractal));
	fractal->img.addr = mlx_get_data_addr(fractal->img.img,
			&fractal->img.bits_per_pixel,
			&fractal->img.line_length, &fractal->img.endian);
	render_fractal(fractal);
}

static void	parsero(int argc, char **argv, t_fractal *fractal)
{
	t_lim	lim;

	ft_memset(&lim, 0, sizeof(t_lim));
	fractal->lim = lim;
	if (argc >= 2 && !ft_strncmp(argv[1], "julia", 5) && !argv[1][5])
		julia(fractal, argv, argc);
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
