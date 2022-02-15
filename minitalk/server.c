
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include "libft/libft.h"
#include "colors.h"

void receive(int sig)
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
		write(1, &c, 1);
		i = 0;
		c = 0x0;
	}
}

int	main(void)
{
	ft_printf("PID: %d\n", getpid());
	signal(SIGUSR1, receive);
	signal(SIGUSR2, receive);
	while(1)
		pause();
}
