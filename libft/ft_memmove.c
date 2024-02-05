/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 19:27:46 by mmarsa-s          #+#    #+#             */
/*   Updated: 2023/05/02 19:27:52 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <string.h>
//#include <stdio.h>
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*pd;
	const unsigned char	*ps;

	pd = dest;
	ps = src;
	if (pd == ps)
		return (dest);
	if (ps < pd && ps + n > pd)
	{
		pd += n;
		ps += n;
		while (n--)
			*(--pd) = *(--ps);
	}
	else
	{
		while (n--)
			*(pd++) = *(ps++);
	}
	return (dest);
}

/*int	main(void)
{
char str1a[] = "lala22222222";
char str1b[] = "lala22222222";
char str2[] = "hiju444444444";

memmove(str1a, str2, 10);
ft_memmove(str1b, str2, 10);

printf("%s\n", str1a); 
printf("%s", str1b);
}*/