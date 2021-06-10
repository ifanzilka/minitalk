#ifndef SERVER_H
# define SERVER_H
# define COLOR
# define F_NONE		"\033[37m"
# define RED		"\033[31m"
# define GREEN		"\033[32m"
# define CYANE		"\033[36m"
# define F_BOLD		"\033[1m"
# define F_ORANGE	"\033[38m"
# define F_YELLOW	"\033[0;33m"
# define F_BLUE		"\033[34m" 

# include <stdio.h>
# include <limits.h>
# include <stdlib.h>
# include <signal.h>
# include <unistd.h>

# define EOT 10
int		g_flag;

/* Basic Fun */
void	ft_putchar(char c);
size_t	ft_strlen(char *s);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

#endif