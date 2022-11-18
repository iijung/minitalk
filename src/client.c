/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 04:23:34 by minjungk          #+#    #+#             */
/*   Updated: 2022/11/19 07:58:56 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	handler(int sig)
{
	g_mini.sig[0] = sig;
}

static void	send_bit(int pid, int sig)
{
	int	retry;

	if (kill(pid, sig) < 0)
	{
		ft_putstr_fd("No such process\n", 2);
		exit(EXIT_FAILURE);
	}
	retry = 0;
	while (g_mini.sig[0] == 0)
	{
		if (usleep(50) == 0)
			++retry;
		if (retry == 100 && g_mini.sig[0] == 0)
		{
			ft_putstr_fd(RED "Timeout\n" NC, 2);
			exit(EXIT_FAILURE);
		}
	}
}

void	send_char(int pid, int c)
{
	int	bit;
	int	sig;

	bit = 0x80;
	while (bit)
	{
		if (c & bit)
			sig = SIGUSR1;
		else
			sig = SIGUSR2;
		g_mini.sig[0] = 0;
		send_bit(pid, sig);
		if (g_mini.sig[0] != sig)
		{
			ft_putstr_fd("wait and resend...\n", 1);
			sleep(1);
			continue ;
		}
		bit >>= 1;
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*msg;

	if (argc != 3)
	{
		ft_putstr_fd("usage: client <server pid> <message>\n", 2);
		exit(EXIT_FAILURE);
	}
	init(handler);
	ft_printf("client[%d] start...\n", getpid());
	pid = ft_atoi(argv[1]);
	msg = argv[2];
	if (msg == 0 || *msg == 0)
	{
		ft_putstr_fd(RED "No message\n" NC, 2);
		exit(EXIT_FAILURE);
	}
	while (*msg)
		send_char(pid, *msg++);
	send_char(pid, *msg);
	ft_putstr_fd(GREEN "send success\n" NC, 1);
	exit(EXIT_SUCCESS);
}
