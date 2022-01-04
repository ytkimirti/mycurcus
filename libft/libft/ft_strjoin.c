/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 16:07:10 by ykimirti          #+#    #+#             */
/*   Updated: 2022/01/04 17:21:05 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <stdio.h>

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	memsize;
	size_t	i;
	char	*new_str;
	size_t	len_s1;

	len_s1 = ft_strlen(s1);
	memsize = ft_strlen(s1) + ft_strlen(s2) + 1;
	new_str = (char *)malloc(memsize * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	i = 0;
	while (i < memsize && s1[i] != '\0')
	{
		new_str[i] = s1[i];
		i++;
	}
	while (i < memsize)
	{
		new_str[i] = s2[i - len_s1];
		i++;
	}
	return (new_str);
}
