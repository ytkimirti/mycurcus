/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 18:49:42 by ykimirti          #+#    #+#             */
/*   Updated: 2022/01/03 19:18:16 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*ft_strnstr(const char *str,const char *to_find, size_t len)
{
	int	a;
	int	i;

	a = 0;
	if (to_find[0] == '\0')
		return (char *)(str);
	while (str[a] != '\0' && (size_t)a < len)
	{
		i = 0;
		while (str[a + i] == to_find[i] && str[a + i] && to_find[i] && (size_t)a + i < len)
		{
			i++;
		}
		if (to_find[i] == '\0')
			return (char *)(str + a);
		a++;
	}
	return (0);
}

/*#include <string.h>*/

/*int	main(void)*/
/*{*/
	/*char *str1 = "AAAB";*/
	/*char *str2 = "B";*/
	/*int	len = 4;*/

	/*printf("%s\n", ft_strnstr(str1, str2, len));*/
	/*printf("%s\n", strnstr(str1, str2, len));*/
/*}*/
