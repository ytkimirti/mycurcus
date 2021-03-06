#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include "libft/libft.h"
#include "colors.h"

void	send_bit(int pid, bool bit)
{
	if (bit == 1)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	usleep(100);
}

void send_char(int pid, char c)
{
	int i;

	i = 0;
	while (i < 8)
	{
		send_bit(pid, (c >> i) & 0x1);
		i++;
	}
}

void send_str(int pid, char *str)
{
	while (*str)
	{
		send_char(pid, *str);
		str++;
	}
	send_char(pid, '\0');
}


int main(int argc, char **argv)
{
	int pid;
	if (argc != 3)
	{
		ft_printf("Usage:\nclient <pid> <message>");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
	{
		char *errmsg = ft_sprintf(RED "%d" RST " is not a valid PID\n", pid);
		ft_putstr_fd(errmsg, 2);
		free(errmsg);
		exit(1);
	}
	send_str(pid, argv[2]);
}
