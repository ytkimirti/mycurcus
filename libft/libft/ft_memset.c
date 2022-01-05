/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:50:01 by ykimirti          #+#    #+#             */
/*   Updated: 2022/01/05 12:47:15 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memset(void *b, int c, size_t n)
{
	unsigned char	*p;

	p = b;
	while (n > 0)
	{
		n--;
		*p = (unsigned char)c;
		p++;
	}
	return (b);
}
