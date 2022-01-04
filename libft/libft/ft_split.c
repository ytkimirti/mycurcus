/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 17:56:04 by ykimirti          #+#    #+#             */
/*   Updated: 2022/01/04 19:41:25 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	strl(char *str, char key)
{
	int	i;

	i = 0;
	while (str[i] != 0 && str[i] != key)
		i++;
	return (i);
}

static int	find_str(char *str, char key)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (*str != 0)
	{
		while (*str == key && *str != 0)
			str++;
		if (*str == 0)
			return (c);
		c++;
		while (*str != key && *str != 0)
			str++;
	}
	return (c);
}

static char	*strcopy(char *dest, char *src, int n)
{
	int	i;

	i = 0;
	while (*src != 0 && i < n)
	{
		*dest = *src;
		src++;
		dest++;
		i++;
	}
	*dest = 0;
	return (dest);
}

char	**ft_split(char *str, char key)
{
	char	**str_m;
	int		c;
	int		i;

	i = 0;
	c = find_str(str, key);
	str_m = (char **)malloc(sizeof(char *) * (c + 1));
	if (str_m == NULL)
		return (NULL);
	while (i < c)
	{
		while (*str == key && *str != 0)
			str++;
		if (*str == 0)
			return (str_m);
		str_m[i] = (char *)malloc((strl(str, key) + 1) * sizeof(char));
		if (str_m[i] == NULL)
			return (NULL);
		strcopy(str_m[i], str, strl(str, key));
		while (*str != key && *str != 0)
			str++;
		i++;
	}
	return (str_m[c] = 0, str_m);
}
