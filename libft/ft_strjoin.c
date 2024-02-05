/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 12:33:12 by mmarsa-s          #+#    #+#             */
/*   Updated: 2023/05/09 12:33:13 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*result;

	len1 = ft_strlen((char *)(s1));
	len2 = ft_strlen((char *)(s2));
	result = malloc(len1 + len2 + 1);
	if (!result)
		return (NULL);
	ft_strlcpy(result, (char *)s1, len1 + 1);
	ft_strlcat(result, s2, len1 + len2 + 1);
	return (result);
}

/*int	main(void)
{
	const char	s1 [] = "tengo el culo";
	const char	s2 [] = " pelao";
	char *ptr;

	ptr = ft_strjoin(s1, s2);
	printf("%s\n", ptr);
	return (ptr);
}*/