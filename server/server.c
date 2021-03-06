/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 23:28:39 by malbrand          #+#    #+#             */
/*   Updated: 2021/11/04 23:56:06 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	ft_print_buff(int pos)
{
	write(1, g_buff, pos);
}

void	ft_add(int n)
{
	static unsigned char	c;
	static int				i;
	static int				pos;

	c |= (n << i++);
	if (i > 7)
	{
		g_buff[pos] = c;
		pos++;
		if (pos == SIZE || c == '\0')
		{
			ft_print_buff(pos);
			pos = 0;
		}
		i = 0;
		c = 0;
	}
}

void	ft_sig1(int n)
{
	(void)n;
	ft_add(1);
}

void	ft_sig2(int n)
{
	(void)n;
	ft_add(0);
}

int	main(void)
{
	int	pid;
	int	i;

	i = 0;
	pid = getpid();
	write(1, "PID : ", 6);
	ft_putnbr(pid);
	write(1, "\n", 1);
	signal(SIGUSR1, ft_sig1);
	signal(SIGUSR2, ft_sig2);
	while (1)
		i++;
	return (0);
}
