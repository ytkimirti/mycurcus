/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 19:39:05 by ykimirti          #+#    #+#             */
/*   Updated: 2022/01/05 16:09:14 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	char	mychr;

	if (nb == -2147483648)
	{
		ft_putnbr_fd(nb / 10, fd);
		write(fd, "8", 1);
	}
	else if (nb < 0)
	{
		write(fd, "-", 1);
		ft_putnbr_fd(-nb, fd);
	}
	else if (nb > 9)
	{
		ft_putnbr_fd(nb / 10, fd);
		mychr = (nb % 10) + '0';
		write(fd, &mychr, 1);
	}
	else
	{
		mychr = (nb % 10) + '0';
		write(fd, &mychr, 1);
	}
}
