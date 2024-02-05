/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:42:14 by mmarsa-s          #+#    #+#             */
/*   Updated: 2023/05/23 16:42:16 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;
	char			*result;

	i = 0;
	str = malloc((ft_strlen((char *)(s)) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	result = str;
	while (*s)
	{
		*str = f(i, *s);
		i++;
		str++;
		s++;
	}
	*str = '\0';
	return (result);
}
