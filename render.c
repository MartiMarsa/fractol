/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:40:51 by mmarsa-s          #+#    #+#             */
/*   Updated: 2024/01/30 15:40:53 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// necesitas una funcion que itera los pixeles y se los va a pasar a otra que los tome.
//
// hay que escalar las coordenadas del fractal al tamaño de la ventana.
//
// usamos funciones que usen aritmetica de vectores para operar con numeros complejos.
//
// renderizaremos los valores que no escapan al infinito. 

void    handle_pixel(int x, int y, t_fractal *fractal)
{

}





void    render_fractal(t_fractal *fractal)
{
    int x;
    int y;

    y = -1;
    while (++y < HEIGHT)
    {
        x = -1;
        while (++x < WIDTH)
        {
            handle_pixel(x, y, fractal)
        }
    }
    
}