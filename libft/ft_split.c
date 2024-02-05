/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 18:58:50 by mmarsa-s          #+#    #+#             */
/*   Updated: 2023/05/09 18:58:52 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	countsplit(const char *s, char c)
{
	int	count;
	int	path;

	count = 0;
	path = 0;
	if (*s == '\0')
		return (0);
	while (*s != '\0')
	{
		if (*s == c)
			path = 0;
		else if (path == 0)
		{
			path = 1;
			count++;
		}
		s++;
	}
	return (count);
}

static int	lengthsubstr(const char *s, char c, int i)
{
	int	len;

	len = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		len++;
		i++;
	}
	return (len);
}

static char	**flyingfree(char **result, int j)
{
	while (j > 0)
	{
		j--;
		free((void *)result[j]);
	}
	free(result);
	return (NULL);
}

static char	**split_fc(const char *s, char **result, char c, int count)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (s[i] != '\0' && j < count)
	{
		k = 0;
		while (s[i] == c)
			i++;
		result[j] = (char *)malloc(sizeof(char) * lengthsubstr(s, c, i) + 1);
		if (!result[j])
			return (flyingfree(result, j));
		while (s[i] != '\0' && s[i] != c)
			result[j][k++] = s[i++];
		result[j][k] = '\0';
		j++;
	}
	result[j] = 0;
	return (result);
}

char	**ft_split(const char *s, char c)
{
	char	**result;
	int		count;

	if (!s)
		return (NULL);
	count = countsplit(s, c);
	result = malloc(sizeof(char *) * (count + 1));
	if (!result)
		return (NULL);
	return (split_fc(s, result, c, count));
}

/*void print(char **strings)
{
    int i = 0;
    while (strings[i] != NULL)
    {
        printf("%s\n", strings[i]);
        i++;
    }
}
int	main(void)
{
	const char	str[] = "Hoy es martes 13 de junio";
	char		c = ' ';
	char		**lel;

	lel = ft_split(str, c);
	print(lel);
	free(lel);
	return (0);
}*/