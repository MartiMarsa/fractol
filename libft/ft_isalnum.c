/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:14:27 by mmarsa-s          #+#    #+#             */
/*   Updated: 2023/05/02 15:14:29 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <ctype.h>
//#include <stdio.h>
#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c > 64 && c < 91) || (c > 96 && c < 123))
		return (1);
	else if (c > 47 && c < 58)
		return (1);
	else
		return (0);
}

/*int	main(void)
{
	int	x;
	int	y;

	y = ft_isalnum(57);
	x = isalnum(57);
	printf("%d\n%d\n", x, y);
	return (0);
}*/
