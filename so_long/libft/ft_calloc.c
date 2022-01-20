/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 13:58:35 by ykimirti          #+#    #+#             */
/*   Updated: 2022/01/04 19:40:35 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	char	*p;
	size_t	i;

	p = malloc(count * size);
	if (p == NULL)
		return (NULL);
	i = 0;
	while (i < count * size)
	{
		p[i] = 0;
		i++;
	}
	return ((void *)(p));
}
