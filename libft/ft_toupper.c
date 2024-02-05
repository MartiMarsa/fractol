/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 19:30:55 by mmarsa-s          #+#    #+#             */
/*   Updated: 2023/05/05 19:30:57 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <ctype.h>
//#include <stdio.h>
#include "libft.h"

int	ft_toupper(int c)
{
	if (c > 96 && c < 123)
	{
		c = c - 32;
		return (c);
	}
	else
		return (c);
}

/*int main(void)
{
	int c;
	int b;

	c = toupper(120);
	b = ft_toupper('b');
	printf("%d\n%d\n", c, b);
	return (0);
}*/