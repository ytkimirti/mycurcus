/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 14:11:34 by ykimirti          #+#    #+#             */
/*   Updated: 2022/01/05 12:55:34 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		len;
	char	*new_str;

	len = ft_strlen(s);
	new_str = (char *)malloc((len + 1) * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	while (len >= 0)
	{
		new_str[len] = s[len];
		len--;
	}
	return (new_str);
}
