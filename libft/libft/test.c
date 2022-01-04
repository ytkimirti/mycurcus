/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 19:42:47 by ykimirti          #+#    #+#             */
/*   Updated: 2022/01/04 19:43:48 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void	myprint(char *str, int len)
{
	while (len > 0)
	{
		len--;
		if (*str == '\0')
			write(1, &"^", 1);
		else
			write(1, str, 1);
		str++;
	}
	write(1, "\n", 1);
}
