/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 14:20:14 by ykimirti          #+#    #+#             */
/*   Updated: 2022/01/06 15:54:08 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		memsize;
	char	*new_str;
	int		i;

	if (!s)
		return (NULL);
	memsize = min((int)ft_strlen(s) - (int)start, (int)len) + 1;
	if (memsize <= 0)
		return (ft_strdup(""));
	new_str = (char *)malloc(memsize);
	if (new_str == NULL)
		return (NULL);
	i = 0;
	while (i < memsize - 1)
	{
		new_str[i] = s[start + i];
		i++;
	}
	new_str[memsize - 1] = '\0';
	return (new_str);
}
