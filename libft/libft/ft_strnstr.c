/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 18:49:42 by ykimirti          #+#    #+#             */
/*   Updated: 2022/01/04 19:42:27 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	int	a;
	int	i;

	a = 0;
	if (to_find[0] == '\0')
		return ((char *)(str));
	while (str[a] != '\0' && (size_t)a < len)
	{
		i = 0;
		while (str[a + i] == to_find[i] && str[a + i]
			&& to_find[i] && (size_t)a + i < len)
		{
			i++;
		}
		if (to_find[i] == '\0')
			return ((char *)(str + a));
		a++;
	}
	return (0);
}
