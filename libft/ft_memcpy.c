/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:30:15 by mmarsa-s          #+#    #+#             */
/*   Updated: 2023/05/02 18:30:17 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*pdest;
	unsigned char	*psrc;

	if (!dest && !src)
		return (NULL);
	pdest = (unsigned char *)dest;
	psrc = (unsigned char *)src;
	while (n-- > 0)
		*pdest++ = *psrc++;
	return (dest);
}

/*Convertir los punteros void* en punteros 
unsigned char* es una forma común de 
ralizar operaciones de copia de memoria en C. 
La razón es que los punteros void* 
n tienen un tipo de dato asociado, lo que significa
 que el compilador no sabe cómo 
iterpretar los datos apuntados por el puntero.
E cambio, los punteros unsigned char* son punteros
 a bytes y tienen un tamaño
dfinido de 1 byte. Al tratar los datos como bytes individuales,
 se puede acceder
ycopiar correctamente el contenido de la memoria, 
independientemente del tipo de 
dtos subyacente.
Etonces, al convertir los punteros void* en punteros
 unsigned char* en la 
iplementación de ft_memcpy(), se puede acceder y 
copiar correctamente cada 
bte de la memoria de origen y destino, sin importar su tipo de dato 
subyacente.
amacenamos la direccion de inicio del bloque 
de memoria de destino en una variable
auxiliar antes de realizar la copia porque esta 
es la direccion que devuelve la funcion*/