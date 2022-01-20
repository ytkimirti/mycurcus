/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 17:22:13 by ykimirti          #+#    #+#             */
/*   Updated: 2022/01/06 15:56:34 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "libft.h"
#include <stdio.h>

static bool	test_set(const char c, const char *set)
{
	while (*set != 0)
	{
		if (c == *set++)
			return (true);
	}
	return (false);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	const char	*start;
	const char	*end;
	char		*new_str;
	int			i;

	if (!s1 || !set)
		return (NULL);
	if (ft_strlen(s1) == 0)
		return (ft_strdup(""));
	start = s1;
	while (test_set(*start, set))
		start++;
	if (*start == '\0')
		return (ft_strdup(""));
	end = s1 + ft_strlen(s1) - 1;
	while (test_set(*end, set))
		end--;
	new_str = (char *)malloc((end - start + 2) * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	i = 0;
	while (start <= end)
		new_str[i++] = *start++;
	new_str[i] = '\0';
	return (new_str);
}
