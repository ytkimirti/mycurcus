/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:10:08 by ykimirti          #+#    #+#             */
/*   Updated: 2022/01/13 00:44:52 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"

int	ft_putstr(char *str)
{
	char *mem;

	mem = str;
	while (*str)
		write(1, str++, 1);
	return (str - mem);
}

int	print_pointer(unsigned long int p)
{
	char	str[16];
	int		i;
	int		len;

	if (p == 0)
		return (ft_putstr("0x0"));
	len = ft_putstr("0x");
	ft_memset(str, 0, 16);
	i = 0;
	while (p > 0)
	{
		str[i++] = "0123456789abcdef"[p % 16];
		p /= 16;
	}
	while (i--)
		len += write(0, &str[i], 1);
	return (len);
}

int	ft_putnbr_unsigned(unsigned int nb, int numdigit)
{
	char		mychr;

	if (nb > 9)
	{
		numdigit = ft_putnbr_unsigned(nb / 10, numdigit + 1);
		mychr = (nb % 10) + '0';
		write(0, &mychr, 1);
	}
	else
	{
		mychr = (nb % 10) + '0';
		write(0, &mychr, 1);
	}
	return (numdigit);
}

int	ft_putnbr(int nb, int numdigit)
{
	char	mychr;

	if (nb == -2147483648)
	{
		ft_putnbr(nb / 10, numdigit + 1);
		write(0, "8", 1);
		return (11);
	}
	else if (nb < 0)
	{
		write(0, "-", 1);
		numdigit = ft_putnbr(-nb, numdigit + 1);
	}
	else if (nb > 9)
	{
		numdigit = ft_putnbr(nb / 10, numdigit + 1);
		mychr = (nb % 10) + '0';
		write(0, &mychr, 1);
	}
	else
	{
		mychr = (nb % 10) + '0';
		write(0, &mychr, 1);
	}
	return (numdigit);
}


int	print_arg(char c, va_list ap)
{
	/*printf("Printing: %c\n", c);*/
	if (c == 'c')
	{
		int mychar = va_arg(ap, int);
		return (write(1, &mychar, 1));
	}
	if (c == 's')
		return (ft_putstr(va_arg(ap, char *)));
	if (c == 'p')
		return (print_pointer(va_arg(ap, unsigned long int)));
	if (c == 'd')
		return (ft_putnbr(va_arg(ap, int), 0));
	if (c == 'u')
		return (ft_putnbr_unsigned(va_arg(ap, unsigned int), 1));


	return (0);
}

int	ft_printf(const char *key, ...)
{
	va_list ap;
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
		else {
			len += write(1, &key[i], 1);
		}
		i++;
	}

	va_end(ap);

	return (len);
}

int	main(void)
{
	int *p = (int *)23421;
	int	mein_count = ft_printf("m >%p\n", p);
	int orig_count = printf("o >%p\n", p);

	printf("\nmein count: %d\norig count: %d", mein_count, orig_count);
}
