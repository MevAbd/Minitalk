#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#define TTS 650

void	ft_error(void)
{
	write(1, "Error\n", 6);
}

int	ft_atoi(char const *s)
{
	int	i;
	int	ret;
	int	neg;

	i = 0;
	ret = 0;
	neg = 1;
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == ' ')
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			neg *= -1;
		i++;
	}
	if (s[i] == '-' || s[i] == '+')
		return (0);
	while (s[i] >= '0' && s[i] <= '9')
	{
		ret = ret * 10 + s[i] - '0';
		i++;
	}
	ret = ret * neg;
	return (ret);
}

void	ft_binary(char c, int pid)
{
	int		i;

	i = 0;
	while (i < 8)
	{
		if ((c & 0x01) == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep (TTS);
		c >>= 1;
		i++;
	}
}

int main(int ac, char **av)
{	
	int	pid;
	int	i;

	i = 0;
	if (ac != 3)
	{
		ft_error();
		return (0);
	}
	else
	{
		pid = ft_atoi(av[1]);
		while (av[2][i] != '\0')
		{
			ft_binary(av[2][i], pid);
			i++;
		}
		ft_binary(av[2][i], pid);
	}
	return (0);
}    
