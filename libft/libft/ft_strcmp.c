/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:56:29 by ykimirti          #+#    #+#             */
/*   Updated: 2022/01/03 17:49:36 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	c;
	int				diff;

	c = 0;
	diff = 0;
	while ((c < n) && !diff && (s1[c] != '\0') && (s2[c] != '\0'))
	{
		diff = (unsigned char)s1[c] - (unsigned char)s2[c];
		c++;
	}
	if (c < n && !diff && (s1[c] == '\0' || s2[c] == '\0'))
		diff = (unsigned char)s1[c] - (unsigned char)s2[c];
	return (diff);
}

/*int	ft_memcmp(const char *s1, const char *s2, size_t n)*/
/*{*/
	/*while (n > 0 && *s1 == *s2)*/
	/*{*/
		/*n--;*/
		/*s1++;*/
		/*s2++;*/
	/*}*/
	/*if (n <= 0)*/
		/*return (0);*/
	/*return ((int)(*(unsigned char *)s1 - *(unsigned char *)s2));*/
/*}*/
