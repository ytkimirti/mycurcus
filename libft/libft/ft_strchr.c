/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 16:36:14 by ykimirti          #+#    #+#             */
/*   Updated: 2022/01/04 19:41:28 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

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

/*int	main(void)*/
/*{*/
	/*printf("%s\n", ft_strchr("Helloa", '\0'));*/
/*}*/
