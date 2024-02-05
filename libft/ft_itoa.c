/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:52:31 by mmarsa-s          #+#    #+#             */
/*   Updated: 2023/05/23 14:52:33 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

static int	ft_lenint(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
	{
		i += 2;
		n = n / 10;
		n = n * -1;
	}
	if (n < 0)
	{
		i++;
		n = n * -1;
	}
	while (n >= 1)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	i = ft_lenint(n);
	str = malloc((i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[i--] = '\0';
	if (n < 0)
	{
		n = n * -1;
		*str = '-';
	}
	while (n >= 1)
	{
		str[i] = n % 10 + 48;
		n = n / 10;
		i--;
	}
	return (str);
}

/*int	main(void)
{
	int		n;
	char	*lel;

	n = 0;
	lel = ft_itoa(n);
	printf("%s\n", lel);
	return (0);
}*/