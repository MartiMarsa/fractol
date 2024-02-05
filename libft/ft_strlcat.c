/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 19:03:13 by mmarsa-s          #+#    #+#             */
/*   Updated: 2023/05/05 19:03:25 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	dst_len;
	size_t	src_len;

	i = 0;
	j = 0;
	src_len = ft_strlen((char *)(src));
	while (dst[i] != '\0' && i < dstsize)
		i++;
	dst_len = i;
	if (i == dstsize)
		return (dst_len + src_len);
	while (src[j] != '\0' && j < dstsize - dst_len - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (dst_len + src_len);
}

/*int	main(void)
{

	char sr [] = "789";
	char dst [6] = "123456";
	char dst2 [6] = "123456";
	size_t x;
	size_t y;

	x = ft_strlcat(dst, sr, 6);
	y = strlcat(dst2, sr, 6);
	printf("%zu\n%s\n%zu\n%s", x, dst, y, dst2);
	return (0);
}*/
