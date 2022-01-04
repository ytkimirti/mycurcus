/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 13:11:46 by ykimirti          #+#    #+#             */
/*   Updated: 2022/01/04 19:41:12 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memcpy(char *dst, const char *src, size_t n)
{
	if (dst == src)
		return (dst);
	while (n > 0)
	{
		n--;
		dst[n] = src[n];
	}
	return (dst);
}
