/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 04:23:34 by minjungk          #+#    #+#             */
/*   Updated: 2022/09/08 07:45:56 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static t_socket	g_server;

static int	send(siginfo_t *info)
{
	if (info == 0 || g_server.message == 0)
		return (-1);
	g_server.read_bit++;
	g_server.read_buf = (g_server.message[0] >> (8 - g_server.read_bit)) & 1;
	if (g_server.read_buf)
		kill(g_server.pid, SIGUSR1);
	else
		kill(g_server.pid, SIGUSR2);
	if (g_server.read_bit == 8)
	{
		g_server.read_bit = 0;
		if (*g_server.message == 0)
			g_server.pid = 0;
		++g_server.message;
	}
	return (0);
}

static void	handler(int sig, siginfo_t *info, void *ucontext)
{
	(void)ucontext;
	if (info == 0)
		return ;
	if (sig == SIGUSR1)
	{
		if (g_server.pid)
			send(info);
		else
			ft_printf("send success\n");
		return ;
	}
	else
		ft_putstr_fd("error occur\n", 2);
	g_server.pid = 0;
}

int	main(int argc, char **argv)
{
	struct sigaction	act;

	if (argc != 3)
	{
		ft_printf("usage: client <server pid> <message>\n");
		return (0);
	}
	g_server.pid = ft_atoi(argv[1]);
	g_server.message = argv[2];
	sigemptyset(&act.sa_mask);
	sigaddset(&act.sa_mask, SIGUSR1);
	sigaddset(&act.sa_mask, SIGUSR2);
	act.sa_handler = 0;
	act.sa_sigaction = handler;
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, 0);
	sigaction(SIGUSR2, &act, 0);
	ft_printf("client[%d] start...\n", getpid());
	kill(0, SIGUSR1);
	while (g_server.pid)
		pause();
	ft_printf("client[%d] stop...\n", getpid());
	return (0);
}
