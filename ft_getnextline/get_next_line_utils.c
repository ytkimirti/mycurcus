/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 15:54:47 by ykimirti          #+#    #+#             */
/*   Updated: 2022/01/08 18:09:57 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s != 0)
	{
		s++;
		len++;
	}
	return (len);
}
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
	{
		new_str = malloc(sizeof(char));
		new_str[0] = '\0';
		return (new_str);
	}
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

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0' && *s != (char)c)
	{
		s++;
	}
	if (c != '\0' && *s == '\0')
		return (NULL);
	return ((char *)(s));
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	memsize;
	size_t	i;
	char	*new_str;
	size_t	len_s1;

	if (!s1 || !s2)
		return (NULL);
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
