static char	g_bi;

int	ft_convdec(int value)
{
	int	pow;
	int	dec;
	int	modulo;

	pow = 1;
	dec = 0;
	modulo = 0;
	while (value > 0)
	{
		modulo = value % 10;
		if (modulo == 1)
			dec += pow;
		value /= 10;
		pow *= 2;
	}
	return (dec);
}

void	ft_conv(char *str)
{
	int		dec;
	char	c;

	dec = ft_atoi(str);
	c = ft_convdec(dec);
	write(1, &c, 1);
}

void	ft_handler(int sig, siginfo_t *info, void *secret)
{
	pid_t	pid;

	(void)secret;
	pid = info->si_pid;
	if (sig == SIGUSR1)
		g_bi = '0';
	if (sig == SIGUSR2)
		g_bi = '1';
	usleep(100);
	kill(pid, SIGUSR1);
}

int	ft_fill(char *str, int nb)
{
	str[nb] = g_bi;
	nb++;
	if (nb == 8)
	{
		ft_conv(str);
		nb = 0;
		return (nb);
	}
	return (nb);
}

int	main(void)
{
	char				str[8];
	int					nb;
	struct sigaction	s_sa;
	int					er;
	pid_t				pid;

	nb = 0;
	er = 0;
	pid = getpid();
	s_sa.sa_sigaction = ft_handler;
	sigemptyset(&s_sa.sa_mask);
	s_sa.sa_flags = SA_SIGINFO;
	er = sigaction(SIGUSR1, &s_sa, NULL );
	er = sigaction(SIGUSR2, &s_sa, NULL );
	write(1, "PID : ", 6);
	ft_putnbr(pid);
	write(1, "\n", 1);
	while (1)
	{
		pause();
		if (er == -1)
			return (EXIT_FAILURE);
		nb = ft_fill(str, nb);
	}
}
