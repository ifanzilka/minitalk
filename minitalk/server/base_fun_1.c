#include "server.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	i = ft_strlen(s);
	if (i == 0)
		return ;
	write(fd, s, i);
	return ;
}

void	ft_putnbr_fd(int n, int fd)
{
	char	c[12];
	int		i;

	i = 0;
	if (n == 0)
		write(fd, "0", 1);
	else
	{
		if (n < 0)
		{
			c[i] = n % (-10) * (-1) + '0';
			n = n / 10 * (-1);
			write(fd, "-", 1);
			i++;
		}
		while (n > 0)
		{
			c[i] = n % 10 + '0';
			i++;
			n = n / 10;
		}
		while (i-- > 0)
			write(fd, &c[i], 1);
	}
}
