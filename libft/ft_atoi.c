/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:07:59 by mmarsa-s          #+#    #+#             */
/*   Updated: 2023/05/02 16:08:00 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdlib.h>
//#include <stdio.h>
#include "libft.h"

int	ft_atoi(const char *s1)
{
	int	i;
	int	sign;
	int	num;

	i = 0;
	sign = 1;
	num = 0;
	while (s1[i] == 32 || (s1[i] > 8 && s1[i] < 14))
		i++;
	if (s1[i] == '-')
		sign = -1;
	if (s1[i] == '-' || s1[i] == '+')
		i++;
	while (s1[i] > 47 && s1[i] < 58)
	{
		num = num * 10 + (s1[i] - 48);
		i++;
	}
	return (num * sign);
}

/*int	main(void)
{
	char s1[] = "      -55645sdf645";
	int	x;
	int	y;

	x = atoi(s1);
	y = ft_atoi(s1);
	printf("%d\n%d\n", x, y);
	return (0);
}*/
