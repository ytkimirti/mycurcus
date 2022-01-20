#include "libft.h"
#include <stdio.h>	

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


char    *ft_strmapi(char const *s, char (*kullan)(unsigned int, char))
{
	char            *array;
	unsigned int    i;
	if (s == NULL)
		return (NULL);
	array = (char *)malloc(ft_strlen(s) + 1);
	if (array == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		array[i] = kullan(i, s[i]);
		i++;


	}
	array[i] = '\0';
	return (array);


}

char new_toupper(char c)
{
	// Buyuk harf yap
	// 	return (c);
	// 	
	return (c);
}

char kullan(unsigned int i, char c)
{
	return (c + i);
}

int	main(void)
{
	char *str = "abcde";
	char *new = NULL;

	new = ft_strmapi(str, kullan);

	printf("%s\n", new);
}

