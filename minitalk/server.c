/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:44:54 by ykimirti          #+#    #+#             */
/*   Updated: 2022/05/17 14:44:58 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include "libft/libft.h"
#include "colors.h"

void receive(int sig, siginfo_t *info, void *ucontext)
{
	static char c = 0;
	static int i = 0;
	int msg;

	(void)info;
	(void)ucontext;
	msg = 0;
	if (sig == SIGUSR1)
		msg = 0x1;
	else if (sig == SIGUSR2)
		msg = 0x0;
	c |= msg << i;
	i++;
	if (i == 8)
	{
		write(1, &c, 1);
		i = 0;
		c = 0x0;
	}
}

int	main(void)
{
	struct sigaction sg = { 0 };
	ft_printf("PID: %d\n", getpid());
	sg.sa_sigaction = &receive;
	sigaction(SIGUSR1, &sg, NULL);
	sigaction(SIGUSR2, &sg, NULL);

	while(1)
		pause();
}
