#ifndef SERVER_H
# define SERVER_H
# define SIZE 50000

#include <unistd.h>
#include <signal.h>

char buff[SIZE];
int	pos;

void	ft_add(int n);
void	ft_print_buff(void);
void	ft_putchar(char c);
void	ft_putnbr(int n);
int	ft_strlen(char *str);

#endif
