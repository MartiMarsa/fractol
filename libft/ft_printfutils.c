/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfutils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:19:08 by mmarsa-s          #+#    #+#             */
/*   Updated: 2023/10/10 17:19:10 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printc(int c, int len)
{
	len++;
	if (write(1, &c, 1) == -1)
		return (-1);
	return (len);
}

int	ft_prints(char *str, int len)
{
	if (!str)
		str = "(null)";
	while (*str && len != -1)
		len = ft_printc(*str++, len);
	return (len);
}

int	ft_printi(int n, int len)
{
	char	*itoa;

	itoa = ft_itoa((long)n);
	if (!itoa)
		return (-1);
	len = ft_prints(itoa, len);
	free(itoa);
	return (len);
}

int	ft_printu(int n, int len)
{
	char			*itoa;
	unsigned int	nb;

	nb = n;
	if (n < 0)
		nb = n + 4294967296;
	itoa = ft_itoa((long) nb);
	if (!itoa)
		return (-1);
	len = ft_prints(itoa, len);
	free(itoa);
	return (len);
}
