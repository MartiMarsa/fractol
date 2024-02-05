/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:43:00 by mmarsa-s          #+#    #+#             */
/*   Updated: 2023/05/08 12:43:03 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <string.h>
//#include <stdio.h>
#include "libft.h"

char	*ft_strnstr(const char *h, const char *n, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*n == '\0')
		return ((char *)(h));
	while (h[i] != '\0' && i < len)
	{
		j = 0;
		while (h[i + j] == n[j] && h[i + j] != '\0' && i + j < len)
		{
			if (n[j + 1] == '\0')
				return ((char *)(h + i));
			j++;
		}
		i++;
	}
	return (NULL);
}

/*int	main(void)
{
	const	char s1[] = "Estas flipando chaval";
	const	char s2[] = "flipando";
	size_t	n;
	char	*r;
	char	*p;
	n = 25;

	p = ft_strnstr(s1, s2, n);
	r = strnstr(s1, s2, n);
	printf("%p\n%p\n", r, p);
	return (0);
}*/