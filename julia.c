/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:53:37 by mmarsa-s          #+#    #+#             */
/*   Updated: 2024/02/01 15:53:38 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_atodbl(char *str, double *c)
{
	double	dec;
	double	result;

	result = 0;
	dec = 0.1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9' && *str)
		result = result * 10 + (*str++ - '0');
	if (*str == '.')
	{
		str++;
		while (*str >= '0' && *str <= '9' && *str)
		{
			result = result + (*str++ - '0') * dec;
			dec *= 0.1;
		}
	}
	if (result > 2 || *str)
		return (1);
	if (str[0] == '-')
		result *= -1;
	*c = result;
	return (0);
}

static void	set_parameters(t_fractal *fractal, char **argv, int argc)
{
	int	flag;

	flag = 0;
	if (argc == 4)
	{
		flag += ft_atodbl(argv[2], &fractal->lim.cr);
		flag += ft_atodbl(argv[3], &fractal->lim.cim);
	}
	if (argc != 4 || flag > 0)
	{
		ft_printf("\nPlease provide valid parameters for the Julia set");
		ft_printf("within the range of -2.0 to 2.0.\nExample: ");
		ft_printf("./fractol julia 0.3 -0.56\n\n");
		exit (1);
	}
}

void	julia(t_fractal *fractal, char **argv, int argc)
{
	double	max_limit;

	max_limit = 2.0;
	fractal->lim.cr = 0.4;
	fractal->lim.cim = 0.2;
	fractal->name = "Julia";
	fractal->type = 2;
	if (argc > 2)
		set_parameters(fractal, argv, argc);
	fractal->maxiter = 100;
	fractal->color = 1;
	fractal->ciao = 15.0;
	fractal->lim.xmin = fmin(fractal->lim.xmin, -max_limit);
	fractal->lim.xmax = fmax(fractal->lim.xmax, max_limit);
	fractal->lim.ymin = fmin(fractal->lim.ymin, -max_limit);
	fractal->lim.ymax = fmax(fractal->lim.ymax, max_limit);
}

void	draw_julia(t_fractal *fractal)
{
	double	x;
	double	y;
	double	temp;

	x = fractal->x;
	y = fractal->y;
	fractal->iter = -1;
	while ((x * x + y * y) <= fractal->ciao
		&& ++fractal->iter < fractal->maxiter)
	{
		temp = x * x - y * y + fractal->lim.cr;
		y = 2 * x * y + fractal->lim.cim;
		x = temp;
	}
}
