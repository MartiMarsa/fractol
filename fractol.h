/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:41:44 by mmarsa-s          #+#    #+#             */
/*   Updated: 2024/01/29 13:41:46 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "mlx/mlx.h"

# define ERROR_MESSAGE	"Error: Invalid command line arguments."\
	"Please use one of the following formats:\n\n1."\
	"For Mandelbrot set: ./fractal mandelbrot\n\n2."\
	"For Julia set: ./fractal julia n1 n2\n\n"\
	"where n1 and n2 are numeric values representing the complex constant.\n"\
	"3. For Burning Ship set: ./fractal burning_ship\n\n"\
	"Please provide the correct command line arguments and try again."

# define WIDTH	1000
# define HEIGHT	1000

/*
 * COLORS
*/
# define BLACK       0x000000  // RGB(0, 0, 0)
# define WHITE       0xFFFFFF  // RGB(255, 255, 255)
# define RED         0xFF0000  // RGB(255, 0, 0)
# define GREEN       0x00FF00  // RGB(0, 255, 0)
# define BLUE        0x0000FF  // RGB(0, 0, 255)

// Psychedelic colors
# define MAGENTA_BURST   0xFF00FF
# define LIME_SHOCK      0xCCFF00
# define NEON_ORANGE     0xFF6600
# define PSYCHEDELIC_PURPLE 0x660066
# define AQUA_DREAM      0x33CCCC
# define HOT_PINK        0xFF66B2
# define ELECTRIC_BLUE   0x0066FF
# define LAVA_RED        0xFF330

# define MOVE 0.1
# define ZOOM 0.7
# define LEFT_CLICK 1
# define ZOOM_OUT 4
# define ZOOM_IN 5
# define ESC 53
# define LEFT 123
# define RIGHT 124
# define DOWN 125
# define UP 126
# define SHIFT 257

/*
 * estructura para numero complejo: parte real y parte imaginaria z = x + yi 
 * aborda los limites
 */
typedef struct s_lim
{
	double	xmin;
	double	xmax;
	double	ymin;
	double	ymax;
	double	cr;
	double	cim;
}	t_lim;

/*
 * estructura para trabajar con mlx, se puede entender como un 
 * buffer de pixeles. Usa valores de mlx_get_data_addr()
 */
typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		height;
	int		width;
}				t_img;

/*
 * INFO DE FRACTAL
 * COSAS DE MLX
 * HOOKS
 * IMAGEN
 */
typedef struct s_fractal
{
	void	*mlx_con;
	void	*mlx_win;
	t_img	img;
	t_lim	lim;
	char	*name;
	int		type;
	int		iterations;
	double	ciao;
	double	x;
	double	y;
}				t_fractal;

//	********	utils
int			ft_strncmp(char *s1, char *s2, int n);
void		ft_putstr_fd(char *s, int fd);
double		scale(double unscaledNum, double minAllowed,
				double maxAllowed, double max);

//	********	main 
int			main(int argc, char **argv);
void	set_buffer(t_img *buffer, t_fractal fractal);

//	********	init
void		init_data(t_fractal *fractal);
void		events_init(t_fractal *fractal);

//	********	render
int			render_fractal(t_fractal *fractal);

//	********	events
void	moving(int key, t_fractal *f);
void	zooming(int key, int x, int y, t_fractal *f);

//	********	clean stuff
void	cleanshit(t_fractal *fractal);
void	alloc_error(void);

//	********	mandelbrot
int		draw_mandelbrot(t_fractal *fractal);
void	mandelbrot(t_fractal *fractal);

//	********	yulia
void	julia(t_fractal *fractal, char **argv);
void	draw_julia(t_fractal *fractal);

//	********	burning shit
void	burning_shit(t_fractal *fractal);
void	draw_shit(t_fractal *ractal);

#endif