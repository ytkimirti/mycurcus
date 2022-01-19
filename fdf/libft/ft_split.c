/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 17:56:04 by ykimirti          #+#    #+#             */
/*   Updated: 2022/01/06 16:36:58 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

static int	find_end(const char *str, char key)
{
	const char	*mem;

	mem = str;
	while (*str != '\0' && *str != key)
		str++;
	return (str - mem + 1);
}

static int	count_char(const char *str, char key)
{
	int	count;

	count = 0;
	while (*str != '\0')
	{
		while (*str == key && *str != '\0')
			str++;
		if (*str == '\0')
			return (count);
		while (*str != key && *str != '\0')
			str++;
		count++;
	}
	return (count);
}

char	**ft_split(const char *str, char key)
{
	char	**list;
	int		list_index;
	int		i;
	int		list_len;

	if (!str)
		return (NULL);
	list_len = count_char(str, key);
	list = (char **)malloc(sizeof(char *) * (list_len + 1));
	if (!list)
		return (NULL);
	list_index = 0;
	while (*str != '\0' && list_index < list_len)
	{
		while (*str == key && *str != '\0')
			str++;
		i = 0;
		list[list_index] = (char *)malloc(sizeof(char) * find_end(str, key));
		while (*str != key && *str != '\0')
			list[list_index][i++] = *str++;
		list[list_index][i] = '\0';
		list_index++;
	}
	list[list_index] = NULL;
	return (list);
}
