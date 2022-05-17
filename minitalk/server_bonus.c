
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


	msg = 0;
	if (sig == SIGUSR1)
		msg = 0x1;
	else if (sig == SIGUSR2)
		msg = 0x0;
	c |= msg << i;
	/*ft_printf(CYN "Received bit: " RED "%d " GRN "i: %d\n" RST, msg, i);*/
	i++;
	if (i == 8)
	{
		// If it's null, send back the acknowladge signal
		if (c == '\0')
		{
			ft_printf(CYN "\nGot message from PID:%d, sending back SIGUSR1\n" RST, info->si_pid);
			kill(info->si_pid, SIGUSR1);
			(void)ucontext;
			/*kill(pid)*/
		}
		else
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
