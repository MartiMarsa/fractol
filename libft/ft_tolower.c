/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 19:41:33 by mmarsa-s          #+#    #+#             */
/*   Updated: 2023/05/05 19:41:35 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <ctype.h>
//#include <stdio.h>
#include "libft.h"

int	ft_tolower(int c)
{
	if (c > 64 && c < 91)
	{
		c = c + 32;
		return (c);
	}
	else
		return (c);
}

/*int main(void)
{
	int c;
	int b;

	c = tolower(67);
	b = ft_tolower('G');
	printf("%d\n%d\n", c, b);
	return (0);
}*/
