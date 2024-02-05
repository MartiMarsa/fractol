/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 19:49:26 by mmarsa-s          #+#    #+#             */
/*   Updated: 2023/05/05 19:49:28 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <string.h>
//#include <stdio.h>
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if ((unsigned char)*s == (unsigned char)c)
			return ((char *)(s));
		else
			s++;
	}
	if ((unsigned char)*s == (unsigned char)c)
		return ((char *)(s));
	return (NULL);
}

/*int	main(void)
{
	char str[] = "alhamdulillah para todos";
	char *lel;
	char *drol;

	lel = ft_strchr(str, 1024);
	drol = strchr(str, 1024);
	printf("%s\n%s\n", lel, drol);
	return (0);
}*/