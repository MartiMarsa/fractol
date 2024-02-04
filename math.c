/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:27:11 by mmarsa-s          #+#    #+#             */
/*   Updated: 2024/01/30 17:27:15 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


// usamos esta funcion para escalar los numeros complejos a los pixeles de la ventana
// tambien nos sirve para escalar el color

double scale(double unscaledNum, double minAllowed, double maxAllowed, double max)
{
	return ((maxAllowed - minAllowed) * (unscaledNum) / max + minAllowed);
}

double fmin(double a, double b) 
{
    return (a < b) ? a : b;
}

double fmax(double a, double b)
{
    return (a > b) ? a : b;
}

