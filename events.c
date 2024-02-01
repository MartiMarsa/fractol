/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:38:54 by mmarsa-s          #+#    #+#             */
/*   Updated: 2024/02/01 13:38:56 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int on_key_pressed(int keysym, t_fractal *fract)
{
	if (keysym == 53)
		mlx_destroy_window(fract->mlx_con, fract->mlx_win);
}

void	events_init(t_fractal *fractal)
{
	mlx_hook(fractal->mlx_win, 2, 0, &on_key_pressed, fractal);
	mlx_hook(fractal->mlx_win, 17, 0, &on_key_pressed, fractal);
	mlx_loop_hook(fractal->mlx_con, mlx_put_image_to_window(fractal->mlx_con, 
					fractal->mlx_win, &fractal->img, 0, 0), fractal);
}