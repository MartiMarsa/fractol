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

/*static double	atodbl(char *str)
{
	double	result;
	int	sign;

	result = 0.0;
	sign = 1;
	if (!str)
		return (0);
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9' && *str)
	{
			result = result * 10 + (*str++ - '0');
	}
	return (result * sign);
}*/

void	julia(t_fractal *fractal, char **argv)
{
	double max_limit;
	
	max_limit = 2.0;
	fractal->name = "Julia";
	fractal->type = 2;
	fractal->iterations = 100;
	fractal->ciao = 4.0;
	fractal->lim.xmin = fmin(fractal->lim.xmin, -max_limit);
	fractal->lim.xmax = fmax(fractal->lim.xmax, max_limit);
	fractal->lim.ymin = fmin(fractal->lim.ymin, -max_limit);
	fractal->lim.ymax = fmax(fractal->lim.ymax, max_limit);
	fractal->lim.cr = atof(argv[2]);
	fractal->lim.cim = atof(argv[3]);
}

int	draw_julia(t_fractal *fractal)
{
	double	x;
	double	y;
	double	temp;
	int		i;

	x = fractal->x;
	y = fractal->y;
	i = 0;
	while ((x * x + y * y) <= fractal->ciao && ++i < fractal->iterations)
	{
		temp = x * x - y * y + fractal->lim.cr;
		y = 2 * x * y + fractal->lim.cim;
		x = temp;
	}
	return (i);
}