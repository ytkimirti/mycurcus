/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 17:41:52 by ykimirti          #+#    #+#             */
/*   Updated: 2022/05/17 18:25:28 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include "libft/libft.h"
#include "colors.h"

void	send_bit(int pid, bool bit)
{
	ft_printf(CYN "Sending bit: " RED "%d\n" RST, bit);
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
	ft_printf(GRN "Sending string" YEL "\"%s\"" RST, str);
	while (*str)
	{
		send_char(pid, *str);
		str++;
	}
	send_char(pid, '\0');
}

void receive(int sig, siginfo_t *info, void *ucontext)
{
	/*info->si_pid == jk*/
}


int main(int argc, char **argv)
{
	struct sigaction sg;
	int pid;

	sg = (struct sigaction){ 0 };
	ft_printf("PID: %d\n", getpid());
	sg.sa_sigaction = &receive;
	sigaction(SIGUSR1, &sg, NULL);
	if (argc != 3)
	{
		ft_printf("Usage:\nclient <pid> <message>");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	send_str(pid, argv[2]);
}
