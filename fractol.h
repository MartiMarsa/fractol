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

# define ERROR_MESSAGE	"escribe bien los argumentos, primo.\n"
# define WIDTH	1000
# define HEIGHT	1000

/*
 * estructura para numero complejo: parte real y parte imaginaria z = x + yi 
 */

typedef struct s_complex
{
	double	x;
	double	y;
}				t_complex;

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
	char	*name;
}				t_fractal;

//	********	utils

int			ft_strncmp(char *s1, char *s2, int n);
void		ft_putstr_fd(char *s, int fd);

//	********	main

int			main(int argc, char **argv);

//	********	init

void		init_data(t_fractal *fractal);

//	********	math

double		scale(double unscaledNum, double minAllowed,
				double maxAllowed, double max);

#endif