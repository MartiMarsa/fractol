/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 17:35:17 by mmarsa-s          #+#    #+#             */
/*   Updated: 2023/05/06 17:35:20 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <string.h>
//#include <stdio.h>
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*ptr;

	i = 0;
	ptr = s;
	while (i < n)
	{
		if (*ptr == (unsigned char)c)
			return ((void *)ptr);
		i++;
		ptr++;
	}
	return (NULL);
}

/*int	main(void)
{
	const	char s1[] = "bonjour";
	int	c;
	size_t	n;
	void	*r;
	void	*p;
	c = 111;
	n = 7;

	p = ft_memchr(s1, c, n);
	r = memchr(s1, c, n);
	printf("%p\n%p\n", r, p);
	return (0);
}*/