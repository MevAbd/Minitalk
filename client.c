#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#define ERROR "test"
#define TIME_TO_SLEEP 100

typedef struct s_var
{
	int	 server_pid;
}	t_var;
//utils
int	ft_strlen(char *str)
{
	int	i;

	 i = 0;
	while (str[i])
		i++;
	return (i);
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
//utils
int	error_arg()
{
	write(1, ERROR, ft_strlen(ERROR));
	return (0);
}

void	char_to_binary(t_var *var, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if ((c & 0x01))
			kill(var->server_pid, SIGUSR1);
		else
			kill(var->server_pid, SIGUSR2);
		i++;
		c >>= 1;
		usleep(TIME_TO_SLEEP);
	}
}

void	string_to_binary(t_var *var, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		char_to_binary(var, str[i]);
		write(1, "\n", 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_var var;

	if (argc != 3)
		return (error_arg());
	var.server_pid = ft_atoi(argv[1]);
	string_to_binary(&var, argv[2]);
}
