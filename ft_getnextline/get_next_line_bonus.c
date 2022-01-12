/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 12:08:51 by ykimirti          #+#    #+#             */
/*   Updated: 2022/01/12 14:09:10 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line_bonus.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif

char	*get_after_nl(char *str)
{
	char	*nl_char;
	char	*new_str;

	nl_char = ft_strchr(str, '\n');
	if (!nl_char)
	{
		free(str);
		return (NULL);
	}
	nl_char++;
	new_str = ft_strdup(nl_char);
	free(str);
	if (!new_str)
	{
		free(new_str);
		return (NULL);
	}
	return (new_str);
}

char	*get_before_nl(char *str)
{
	char	*nl_char;
	size_t	len;
	char	*new_str;

	nl_char = ft_strchr(str, '\n');
	if (!nl_char)
		return (ft_strdup(str));
	len = (nl_char - str) + 1;
	new_str = ft_substr(str, 0, len);
	if (!new_str)
		free(str);
	return (new_str);
}

char	*read_until_nl(int fd, char *str)
{
	int		c;
	char	buff[BUFFER_SIZE + 1];
	char	*mem;

	c = 1;
	while (c > 0 && ft_strchr(str, '\n') == NULL)
	{
		c = read(fd, &buff, BUFFER_SIZE);
		if (c < 0)
		{
			free(str);
			return (NULL);
		}
		buff[c] = '\0';
		mem = str;
		str = ft_strjoin(str, buff);
		free(mem);
	}
	if (!*str)
	{
		free(str);
		return (NULL);
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str[1024];
	char		*before;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	if (str[fd] == NULL)
		str[fd] = ft_strdup("");
	str[fd] = read_until_nl(fd, str[fd]);
	if (!str[fd])
		return (NULL);
	before = get_before_nl(str[fd]);
	if (!before)
		return (NULL);
	str[fd] = get_after_nl(str[fd]);
	return (before);
}
