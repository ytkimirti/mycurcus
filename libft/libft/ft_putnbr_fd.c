/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 19:39:05 by ykimirti          #+#    #+#             */
/*   Updated: 2022/01/04 19:39:38 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_fd(int nb, int fd)
{
	unsigned int	val;
	int				buff;

	val = nb;
	if (nb < 0)
	{
		write(fd, "-", 1);
		val = -nb;
	}
	if (nb != 0)
	{
		buff = (val % 10) + '0';
		ft_putnbr_fd(val / 10, fd);
		write(fd, &buff, 1);
	}
}
