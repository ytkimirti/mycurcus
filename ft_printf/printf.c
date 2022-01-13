/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:10:08 by ykimirti          #+#    #+#             */
/*   Updated: 2022/01/13 12:21:06 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "printf.h"

int	print_arg(char c, va_list ap)
{
	int	mychar;

	if (c == 'c')
	{
		mychar = va_arg(ap, int);
		return (write(1, &mychar, 1));
	}
	if (c == 's')
		return (ft_putstr(va_arg(ap, char *)));
	if (c == 'p')
		return (print_pointer(va_arg(ap, unsigned long int)));
	if (c == 'd')
		return (ft_putnbr(va_arg(ap, int), 1));
	if (c == 'i')
		return (ft_putnbr(va_arg(ap, int), 1));
	if (c == 'u')
		return (ft_putnbr_unsigned(va_arg(ap, unsigned int), 1));
	if (c == 'x')
		return (print_hexadec(va_arg(ap, unsigned int), "0123456789abcdef"));
	if (c == 'X')
		return (print_hexadec(va_arg(ap, unsigned int), "0123456789ABCDEF"));
	if (c == '%')
		return (ft_putstr("%"));
	return (0);
}

int	ft_printf(const char *key, ...)
{
	va_list	ap;
	int		i;
	int		len;

	va_start(ap, key);
	i = 0;
	len = 0;
	while (key[i])
	{
		if (key[i] == '%')
		{
			if (key[i + 1] != 0)
				len += print_arg(key[i + 1], ap);
			i++;
		}
		else
			len += write(1, &key[i], 1);
		i++;
	}
	va_end(ap);
	return (len);
}
