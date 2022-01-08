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
		{
			write(1, &"0", 1);
		}
		else {
			write(1, str, 1);
		}
		str++;
	}
	write(1, "\n", 1);
}
