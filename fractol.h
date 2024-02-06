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
# include "libft/libft.h"

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
# define ZOOM 0.9
# define LEFT_CLICK 1
# define ZOOM_OUT 4
# define ZOOM_IN 5
# define ESC 53
# define LEFT 123
# define RIGHT 124
# define DOWN 125
# define UP 126
# define SHIFT 257
# define SPACEBAR 49
# define Z 6
# define X 7
# define C 8
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
	int		maxiter;
	int		iter;
	int		color;
	int		base;
	double	ciao;
	double	x;
	double	y;
}				t_fractal;

//	********	utils
double		scale(double unscaledNum, double minAllowed,
				double maxAllowed, double max);
int			ft_color(t_fractal	*fractal);
void		my_pixel_put(t_fractal *f, int x, int y, int color);

//	********	main 
int			main(int argc, char **argv);

//	********	init
void		events_init(t_fractal *fractal);

//	********	render
int			render_fractal(t_fractal *fractal);

//	********	events
void		moving(int key, t_fractal *f);
void		zooming(int key, double x, double y, t_fractal *f);

//	********	mandelbrot
void		draw_mandelbrot(t_fractal *fractal);
void		mandelbrot(t_fractal *fractal);

//	********	yulia
void		julia(t_fractal *fractal, char **argv, int argc);
void		draw_julia(t_fractal *fractal);

//	********	burning shit
void		burning_shit(t_fractal *fractal);
void		draw_shit(t_fractal *ractal);

#endif