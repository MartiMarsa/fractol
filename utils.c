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
	int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] != '\0' && s2[i] != '\0' && i < n)
	{
		if ((unsigned char)s1[i] == (unsigned char)s2[i])
			i++;
		else
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	if (i == n)
		return (0);
	else if (s1[i] == '\0' && s2[i] == '\0')
		return (0);
	else if (s1[i] == '\0')
		return (-1);
	else
		return (1);
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

void	set_buffer(t_img *buffer, t_fractal fractal)
{
	buffer->img = mlx_new_image(fractal.mlx_con, WIDTH, HEIGHT);
	buffer->addr = mlx_get_data_addr(&buffer, &buffer->bits_per_pixel, &buffer->line_length, &buffer->endian);
	buffer->height = HEIGHT;
	buffer->width = WIDTH;
}
