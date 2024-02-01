/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 19:18:23 by mmarsa-s          #+#    #+#             */
/*   Updated: 2024/01/26 19:18:27 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//devuelve 0 si los strings son iguales
int	ft_strncmp(char *s1, char *s2, int n)
{
	if (s1 == NULL || s2 == NULL || n < 0)
		return (-1);
	while (*s1 == *s2 && n > 0 && *s1)
	{
		s1++;
		s2++;
		n--;
	}
	return (*s1 - *s2);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!*s || fd < 0)
		return ;
	if (*s)
	{	
		write (fd, s, 1);
		ft_putstr_fd(s + 1, fd);
	}
}

// usamos esta funcion para escalar los numeros complejos a los pixeles de la ventana
double scale(double unscaledNum, double minAllowed, double maxAllowed, double max)
{
	return ((maxAllowed - minAllowed) * (unscaledNum) / max + minAllowed);
}