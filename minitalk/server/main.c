#include "server.h"

/*
**	Example:
** 
**
*/
#include <stdio.h>

void	ft_get_pid(int sig)
{
	static char	pid = 0;
	static int	i = 0;
	static int	num_pid = 0;
	static int	power = 1;

	if (sig == SIGUSR1)
		pid = pid + (1 << i);
	if (++i == 8)
	{	
		i = 0;
		if (pid == EOT)
		{
			g_flag = 0;
			pid = 0;
			usleep(50);
			if (kill(num_pid, SIGUSR1) < 0)
				exit(0);
			num_pid = 0;
			power = 1;
			return ;
		}
		num_pid = (pid - '0') * power + num_pid;
		power = power * 10;
		pid = 0;
	}
}

#include <stdio.h>

void 	ft_get_char(int sig)
{
	static char	ascii = 0;
	static int	power = 0;
	static char str[1001] = {};
	static int 	i = 0;

	usleep(15);
	if (g_flag == 1)
	{
		ft_get_pid(sig);
		return ;
	}
	if (sig == SIGUSR1)
		ascii = ascii + (1 << power);
	power += 1;
	if (power == 8)
	{
		str[i] = ascii;
		i++;
		if (ascii == 0)
		{
			g_flag = 1;
			ft_putstr_fd("\n", 1);

			i = 0;
			str[1000] = 0;
			ft_putstr_fd(str, 1);
	
		}
		power = 0;
		ascii = 0;
	}
}

void 	ft_wait_msg(void)
{	
	if (signal(SIGUSR1, ft_get_char) == SIG_ERR)
		exit (42);
	else if (signal(SIGUSR2, ft_get_char) == SIG_ERR)
		exit (42);
	return ;
}

int 	main(void)
{
	pid_t	pid;

	pid = getpid();
	if (pid <= 0)
	{
		write(1, "Error\nCan't get pid\n", 20);
		exit (0);
	}
	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putstr_fd("\nWait Message...\n", 1);
	ft_wait_msg();
	while (21)
		;
}
