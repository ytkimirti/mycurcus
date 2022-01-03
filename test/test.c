#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

static void	myprint(char *str, int len)
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

static void	test()
{
	char	*str = "BBBB";
	char	buff1[0xF00];
	char	buff2[0xF00];

	memset(buff1, 'A', 20);
	memset(buff2, 'A', 20);

	strlcpy(buff1, str, sizeof(buff1));
	ft_strlcpy(buff2, str, sizeof(buff2));
	myprint(buff1, 20);
	myprint(buff2, 20);
}

static void	stdtest()
{
	char *mem = (char *)malloc(sizeof(char) * g_size);

	int ret = ft_strlcpy(mem, g_str, g_batch);

	printf("Return var: %d\n", ret);
	printf("Memory: %s\n", mem);
}
static void	othertest()
{
	char *mem = (char *)malloc(sizeof(char) * g_size);

	int ret = strlcpy(mem, g_str, g_batch);

	printf("Correct ret: %d\n", ret);
	printf("Correct: %s\n", mem);
}

int	main(void)
{
	/*stdtest();*/
	/*test();*/
	/*othertest();*/
}

