/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 23:33:58 by malbrand          #+#    #+#             */
/*   Updated: 2021/11/04 23:51:05 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H
# define SIZE 10000

# include <unistd.h>
# include <signal.h>

char	g_buff[SIZE];

void	ft_add(int n);
void	ft_print_buff(int pos);
void	ft_putchar(char c);
void	ft_putnbr(int n);
int		ft_strlen(char *str);

#endif
