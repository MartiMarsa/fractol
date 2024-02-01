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
}

void	julia(t_fractal *fractal, char **argv)
{
	fractal->type = 2;
	fractal->iterations = 100;
	fractal->ciao = 6.0;
	fractal->lim.ymin = 2;
	fractal->lim.ymax = -2;
	fractal->lim.xmin = 2;
	fractal->lim.xmax = -2;
	fractal->lim.cr = atodlb(argv[3]);
	fractal->lim.cim = atodlb(argv[4]);
}

void	draw_julia(t_fractal *fractal)
{
	double	x;
	double	y;
	double	temp;
    int     i;

	x = fractal->x;
	y = fractal->y;
	i = -1;
	while ((x * x + y * y) <= fractal->ciao && ++i < fractal->iterations)
	{
		temp = x * x - y * y + fractal->lim.cr;
		y = 2 * x * y + fractal->lim.cim;
		x = temp;
	}
}*/