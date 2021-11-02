#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

//utils
unsigned int	ft_sign(int n)
{
	unsigned int	nb;

	if (n < 0)
		nb = -n;
	else
		nb = n;
	return (nb);
}

unsigned int	ft_count(unsigned int nb)
{
	unsigned int	count;

	count = 0;
	if (nb == 0)
		return (2);
	while (nb != 0)
	{
		count++;
		nb /= 10;
	}
	return (count + 1);
}

char	*ft_itoa(int n, unsigned int j)
{
	char			*res;
	unsigned int	nb;
	unsigned int	count;

	nb = ft_sign(n);
	count = ft_count(nb);
	if (n < 0)
	{
		count++;
		j = 1;
	}
	res = (char *)malloc(sizeof(char) * count);
	if (!(res))
		return (NULL);
	res[--count] = '\0';
	if (n == 0)
		res[0] = '0';
	if (n < 0)
		res[0] = '-';
	while (count > j)
	{
		res[--count] = (nb % 10) + '0';
		nb /= 10;
	}
	return (res);
}
//utils

void	handle_sigusr1(int n)
{
	write(1, "1", 1);
}

void	handle_sigusr2(int n)
{
	write(1, "0", 1);
}

char	*displayPid()
{
	int	pid;
	char	*spid;

	pid = getpid();
	spid = ft_itoa(pid, 0);
	write(1, "PID: ", 6);
	write(1, spid, strlen(spid));
	write(1, "\n", 1);
}

int	main(void)
{
	char	*pid;

	pid = displayPid();
	signal(SIGUSR1, handle_sigusr1);
	signal(SIGUSR2, handle_sigusr2);
	while (1)
		(void)0;
}
