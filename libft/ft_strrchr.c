/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 20:23:08 by mmarsa-s          #+#    #+#             */
/*   Updated: 2023/05/05 20:23:10 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <string.h>
//#include <stdio.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		else
			i--;
	}
	return (NULL);
}

/*int	main(void)
{
	char str[] = "alhamdulillah para todos";
	char *lel;
	char *drol;

	lel = ft_strrchr(str, 116);
	drol = strrchr(str, 116);
	printf("%s\n%s\n", lel, drol);
	return (0);
}*/
