/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:42:53 by mmarsa-s          #+#    #+#             */
/*   Updated: 2023/05/02 15:42:55 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t num)
{
	unsigned char	*p;

	p = ptr;
	while (num-- > 0)
		*p++ = value;
	return (ptr);
}
// se convierte el puntero a un unsigned char* porqué es el tipo de dato 
// más pequeño en C (1 byte) y está funció trabaja byte a byte.
// creamos un bucle while que itera num veces
//esta expresion devuelve el valor de p en la posicion actual y la 
//incrementa en 1
//esta funcion devuelve el puntero al bloque de memoria establecido