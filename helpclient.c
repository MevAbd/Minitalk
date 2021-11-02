void	ft_killbinary(int value, pid_t pid)
{
	int	nb;
	int	power;
	int	div;

	nb = 0;
	power = 10000000;
	div = 128;
	while (power > 0)
	{
		nb += (value / div) * power;
		if ((value / div) == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		pause();
		value = value % div;
		div /= 2;
		power /= 10;
	}
}

void	ft_sendprocess(char *str, pid_t pid)
{
	int	nb;

	nb = 0;
	while (str[nb] != '\0')
	{
		ft_killbinary(str[nb], pid);
		nb++;
	}
}

void	ft_handler(int sig)
{
	sig *= 1;
	usleep(100);
}

int	main(int argc, char **argv)
{
	char			*str;
	pid_t			pid;

	signal(SIGUSR1, ft_handler);
	if (argc != 3)
	{
		write(2, "error ./a.out [pid] [message]", 29);
		return (EXIT_FAILURE);
	}
	str = argv[2];
	pid = ft_atoi(argv[1]);
	ft_sendprocess(str, pid);
	return (0);
}
