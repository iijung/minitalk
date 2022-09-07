/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 04:23:34 by minjungk          #+#    #+#             */
/*   Updated: 2022/09/07 11:25:51 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static t_socket	*head;

int	send(int pid, char *message)
{
	static int	bit = 8;
	static char	*buf;

	if (message)
		buf = message;
	while (buf)
	{
		if (bit == 8)
		{

		}

		server.bit = 0x80;
		while (server.bit)
		{
			if (*server.stream & server.bit)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			pause();
			if (server.err)
				return (-1);
			server.bit >>= 1;
		}
		++server.stream;
		if (*server.stream == 0)
			break ;
	}
	return (0);
}


static void	handler(int sig, siginfo_t *info, void *ucontext)
{
	// send
}

static void	handler(int sig, siginfo_t *info, void *ucontext)
{
	// recv
	(void)ucontext;
	if (sig == SIGUSR2 || info == 0)
	{
		server.ret = -1;
		ft_putstr_fd("error occur\n", 2);
		return ;
	}
	if (sig == SIGUSR1)
	{
		if (send(info`
		ft_putstr_fd("send success\n", 1);
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	act;

	if (argc != 3)
	{
		ft_printf("usage: client <server pid> <message>\n");
		return (0);
	}
	sigemptyset(&act.sa_mask);
	sigaddset(&act.sa_mask, SIGUSR1);
	sigaddset(&act.sa_mask, SIGUSR2);
	act.sa_handler = 0;
	act.sa_sigaction = handler;
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, 0);
	sigaction(SIGUSR2, &act, 0);
	ft_printf("client[%d] start...\n", getpid());
	send_message(ft_atoi(argv[1], argv[2]));
	ft_printf("client[%d] stop...\n", getpid());
	return (server.ret);
}
