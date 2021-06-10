#include "client.h"
/*
** Example:
**	'a' -> 97 num in ascii
**	01100001
**	97 >> 0
**	01100001 & 00000001 = 1 (sent 1)
**	97 >> 1
**  00110000 & 0110000 = 0 (sent 0)
** 	...
*/

void	ft_sent_char(pid_t pid, char c)
{
	int	i;
	int	bit;

	i = 0;
	while (i < 8)
	{
		usleep(100);
		bit = (c >> i) & 1;
		if (bit == 1)
			bit = kill(pid, SIGUSR1);
		else
			bit = kill(pid, SIGUSR2);
		if (bit == -1)
			exit(-42);
		i++;
	}
	return ;
}

void	ft_sent_str(pid_t pid_s, char *s)
{
	int		i;
	pid_t	pid_c;

	i = 0;
	pid_c = getpid();
	if (pid_c <= 0)
	{
		write(1, "Error\nGet pid\n", 14);
		exit (0);
	}
	while (s[i] != '\0')
		ft_sent_char(pid_s, s[i++]);
	ft_sent_char(pid_s, s[i++]);
	while (pid_c > 0)
	{
		i = pid_c % 10 + '0';
		ft_sent_char(pid_s, i);
		pid_c = pid_c / 10;
	}
	ft_sent_char(pid_s, EOT);
	return ;
}

void	ft_finish(int sig)
{
	if (sig == SIGUSR1)
	{
		ft_putstr_fd(GREEN, 1);
		ft_putstr_fd("Messege correctly sent\n", 1);
		ft_putstr_fd(F_NONE, 1);
		exit(0);
	}
}

void	ft_client(char **argv)
{
	pid_t	*pid;

	pid = (pid_t *)ft_atoi(argv[1]);
	if (pid == NULL || kill(*pid, 0) == -1)
	{
		ft_putstr_fd(RED "PID error\n" F_NONE, 2);
		exit(0);
	}
	ft_sent_str(*pid, argv[2]);
	free(pid);
	if (signal(SIGUSR1, ft_finish) == SIG_ERR)
		exit(0);
	while (21)
	{
	}
	return ;
}

int	main(int argc, char *argv[])
{
	if (argc == 3)
		ft_client(argv);
	else
		ft_putstr_fd(RED "Error\nArguments have to be three.\n" F_NONE, 2);
	return (0);
}
