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

/*int	mouse_hook(int key, int x, int y, t_fractal *fractal)
{
    if (key == ZOOM_IN || key == ZOOM_OUT)
        zooming(key, (double)x / WIDTH, (double)y / HEIGHT, fractal);

    render_fractal(fractal);
    return (0);
}*/

/*nt	key_hook(int key, t_fractal *fractal)
{
	if (key >= LEFT && key <= UP)
		moving(key, fractal);
	render_fractal(fractal);
	return (0);
}*/

int destroy(t_fractal *fractal)
{
	if (fractal && fractal->mlx_win)
		mlx_destroy_window(fractal->mlx_con, fractal->mlx_win);
	exit (1);
}

int on_key_pressed(int keysym, t_fractal *fractal)
{
	if (keysym == ESC)
		destroy(fractal);
	return 0;
}

void	events_init(t_fractal *fractal)
{
	mlx_hook(fractal->mlx_win, 2, 0, &on_key_pressed, fractal);
	mlx_hook(fractal->mlx_win, 17, 0, &destroy, fractal);
	//mlx_key_hook(fractal->mlx_con, &key_hook, fractal);
	//mlx_mouse_hook(fractal->mlx_con, &mouse_hook, fractal);
	//mlx_loop_hook(fractal->mlx_con, &render_fractal, fractal);
}