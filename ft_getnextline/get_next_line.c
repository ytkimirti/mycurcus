/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 12:32:41 by ykimirti          #+#    #+#             */
/*   Updated: 2022/01/08 17:24:58 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdbool.h>

#define BUFFER_SIZE 5

/*
 * Return value of this function is the
 * value that should be returned by read_to_str
 *
 * If its null that means it has to read another
 * buffer.
 * */
char	*read_to_str(char **str, char *buffer, int read_count)
{
	char	*tmp;
	if (ft_strchr(buffer, '\n'))
	{
		int	line_size = (ft_strchr(buffer, '\n') - buffer) + 1;

		tmp = ft_substr(buffer, line_size, read_count - line_size);

		char *new_str = ft_strjoin(*str, tmp);
		*str = tmp;

		return (new_str);
	}
	else
	{
		tmp = ft_strnstr(buffer, 0, read_count);
		*str = ft_strjoin(*str, buffer);
		free(tmp);
		return (NULL);
	}
}


int	read_to_str(char **str, char *buffer, int read_count, char **return_val)
{
	char	*old_str;
	char	*new_part;
	int		

	// Free old str and allocate more memory.
	
	/*free(*str);*/
	old_str = *str;

	// Find the optimal read count
	if (ft_strchr(buffer, '\n'))
	{

		read_count = (ft_strchr(buffer, '\n') - buffer) + 1;
		printf("New read_count calculated: %d\n", read_count);
	}

	new_part = ft_strnstr(buffer, 0, read_count);
	printf("new_part: %s\n", new_part);
	
	*str = ft_strjoin(old_str, new_part);
	printf("Newly created string: %s\n", *str);

	return 0;
}

char *get_next_line(int fd)
{
	static char*	str;
	int				read_count;
	char			buff[BUFFER_SIZE];

	str = "";
	while (true)
	{
		read_count = read(fd, buff, BUFFER_SIZE);
		if (read_count == -1)
		{
			free(str);
			return (NULL);
		}
		if (read_count == 0)
			break;
		if (read_to_str(&str, buff, read_count) == true)
		{
			// Found a newline
			return (str);
		}
	}

	return (NULL);
}

int	main(void)
{
	int fd = open("file.txt", O_RDONLY);

	char	buff[100];

	int return_val = read(fd, buff, 100);

	printf("Returned %d\n", return_val);

	printf("BUFF: %s", buff);
}
