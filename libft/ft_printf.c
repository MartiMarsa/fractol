/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <mmarsa-s@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:17:40 by mmarsa-s          #+#    #+#             */
/*   Updated: 2023/10/10 17:17:44 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

static int	ft_printx(unsigned long n, int len, char *base)
{
	if (len != -1 && n > 0)
	{
		if (n >= 16)
			len = ft_printx(n / 16, len, base);
		if (len != -1)
			len = ft_printc(base[n % 16], len);
	}
	else if (len != -1)
		len = ft_printc('0', len);
	return (len);
}

static int	ft_printp(void *str, int len)
{
	unsigned long	ptr;

	ptr = (unsigned long)str;
	len = ft_prints("0x", len);
	if (len == -1)
		return (-1);
	len = ft_printx(ptr, len, "0123456789abcdef");
	if (len == -1)
		return (-1);
	return (len);
}

static int	checkformat(const char *format, va_list vl, int len)
{
	format++;
	if (*format == 'c')
		len = ft_printc((char)va_arg(vl, int), len);
	else if (*format == 's')
		len = ft_prints(va_arg(vl, char *), len);
	else if (*format == 'p')
		len = ft_printp(va_arg(vl, void *), len);
	else if (*format == 'i' || *format == 'd')
		len = ft_printi(va_arg(vl, int), len);
	else if (*format == 'u')
		len = ft_printu(va_arg(vl, unsigned long), len);
	else if (*format == 'x')
		len = ft_printx(va_arg(vl, unsigned int), len, "0123456789abcdef");
	else if (*format == 'X')
		len = ft_printx(va_arg(vl, unsigned int), len, "0123456789ABCDEF");
	else if (*format == '%')
		len = ft_printc(*format, len);
	return (len);
}

int	ft_printf(char const *format, ...)
{
	int			len;
	va_list		vl;

	va_start (vl, format);
	len = 0;
	while ((len >= 0) && *format != '\0')
	{
		if (*format == '%')
		{
			len = checkformat(format, vl, len);
			format += 2;
		}
		else
		{
			len = ft_printc(*format, len);
			format++;
		}
	}
	va_end(vl);
	return (len);
}

/*int	main(void)
{
	int	i;
	int	j;

	i = ft_printf("%u\n", -10);
	ft_printf("%i\n", i);
	j = printf("%u\n", -10);
	ft_printf("%i\n", j);
	return (0);
}*/