#include "server.h"
char buff[SIZE];
int	pos;

void	ft_print_buff(void)
{
	write(1, buff, pos);
}

void	ft_add(int n)
{
	static unsigned char	c = 0;
	static int		i = 0;

	c |= (n << i++);
	if (i > 7)
	{
	//	buff[pos] = c;
	//	pos++;
	//	if (pos == SIZE || c == '\0')
	//	{
	//		ft_print_buff();
	//		pos = 0;
	//	}
		if (c == '\0')
			write(1, "\n", 1);
		else 
			write(1, &c, 1);
		i = 0;
		c = 0;
	}
}

void	ft_sig1()
{
	ft_add(1);
}

void	ft_sig2()
{
	ft_add(0);
}

int	main(void)
{
	int	pid;
	int i;

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
