/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_fun_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 19:38:12 by bmarilli          #+#    #+#             */
/*   Updated: 2021/06/10 19:38:13 by bmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	*ft_atoi(char *str)
{
	long long	result;
	int			*re;

	re = (int *)malloc(sizeof(int));
	if (re == NULL)
		return (NULL);
	result = 0;
	while ('0' <= *str && *str <= '9')
	{
		if (result > INT_MAX)
		{
			free(re);
			return (NULL);
		}
		result = ((*str++) - '0') + result * 10;
	}
	if ((*str < '0' || '9' < *str) && *str != '\0')
	{
		free(re);
		return (NULL);
	}
	*re = (int)(result);
	return (re);
}

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

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	i = ft_strlen(s);
	if (i == 0)
		return ;
	write(fd, s, i);
	return ;
}
