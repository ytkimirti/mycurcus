/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 12:12:56 by ykimirti          #+#    #+#             */
/*   Updated: 2022/01/13 12:13:43 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft/libft.h"

int	ft_putstr(char *str)
{
	char	*mem;

	if (!str)
		return (ft_putstr("(null)"));
	mem = str;
	while (*str)
		write(1, str++, 1);
	return (str - mem);
}

int	print_hexadec(unsigned int p, char *charset)
{
	char	str[16];
	int		i;
	int		len;

	if (p == 0)
		return (ft_putstr("0"));
	ft_memset(str, 0, 16);
	i = 0;
	len = 0;
	while (p > 0)
	{
		str[i++] = charset[p % 16];
		p /= 16;
	}
	while (i--)
		len += write(1, &str[i], 1);
	return (len);
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
		len += write(1, &str[i], 1);
	return (len);
}

int	ft_putnbr_unsigned(unsigned int nb, int numdigit)
{
	char		mychr;

	if (nb > 9)
	{
		numdigit = ft_putnbr_unsigned(nb / 10, numdigit + 1);
		mychr = (nb % 10) + '0';
		write(1, &mychr, 1);
	}
	else
	{
		mychr = (nb % 10) + '0';
		write(1, &mychr, 1);
	}
	return (numdigit);
}

int	ft_putnbr(int nb, int numdigit)
{
	char	mychr;

	if (nb == -2147483648)
	{
		ft_putnbr(nb / 10, numdigit + 1);
		write(1, "8", 1);
		return (11);
	}
	else if (nb < 0)
	{
		write(1, "-", 1);
		numdigit = ft_putnbr(-nb, numdigit + 1);
	}
	else if (nb > 9)
	{
		numdigit = ft_putnbr(nb / 10, numdigit + 1);
		mychr = (nb % 10) + '0';
		write(1, &mychr, 1);
	}
	else
	{
		mychr = (nb % 10) + '0';
		write(1, &mychr, 1);
	}
	return (numdigit);
}
