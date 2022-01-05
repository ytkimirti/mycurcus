/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:56:29 by ykimirti          #+#    #+#             */
/*   Updated: 2022/01/05 12:49:45 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_memcmp(const char *s1, const char *s2, size_t n)
{
	while (n > 0 && *s1 == *s2)
	{
		n--;
		s1++;
		s2++;
	}
	if (n <= 0)
		return (0);
	return ((int)(*(unsigned char *)s1 - *(unsigned char *)s2));
}
