/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 19:36:47 by bmarilli          #+#    #+#             */
/*   Updated: 2021/06/10 19:36:48 by bmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H
# include <stdio.h>
# include <limits.h>
# include <stdlib.h>
# include <signal.h>
# include <unistd.h>

# define COLOR
# define F_NONE		"\033[37m"
# define RED		"\033[31m"
# define GREEN		"\033[32m"
# define CYANE		"\033[36m"
# define F_BOLD		"\033[1m"
# define F_ORANGE	"\033[38m"
# define F_YELLOW	"\033[0;33m"
# define F_BLUE		"\033[34m"
# define EOT 10

/*
** Base fun
*/
int		*ft_atoi(char *str);
size_t	ft_strlen(char *s);
void	ft_putstr_fd(char *s, int fd);

#endif
