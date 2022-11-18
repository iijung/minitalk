/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 04:23:34 by minjungk          #+#    #+#             */
/*   Updated: 2022/11/19 08:21:10 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	handler(int sig, siginfo_t *info, void *uap)
{
	(void)uap;
	while (1)
	{
		if (g_mini.lock)
			break ;
		if (g_mini.cnt == MAXQ)
			break ;
		g_mini.sig[g_mini.cnt] = sig;
		g_mini.pid[g_mini.cnt] = info->si_pid;
		g_mini.cnt++;
		return ;
	}
	if (sig == SIGUSR1)
		kill(info->si_pid, SIGUSR2);
	else
		kill(info->si_pid, SIGUSR1);
}

static struct s_client	*get(int pid)
{
	volatile sig_atomic_t	i;

	if (pid == 0)
		return (NULL);
	i = -1;
	while (++i < MAXQ)
	{
		if (g_mini.client[i].use && g_mini.client[i].pid == pid)
			return (&g_mini.client[i]);
	}
	i = -1;
	while (++i < MAXQ)
	{
		if (g_mini.client[i].use == 0)
		{
			g_mini.client[i].use = 1;
			g_mini.client[i].pid = pid;
			g_mini.client[i].len = 0;
			g_mini.client[i].bit_len = 0;
			return (&g_mini.client[i]);
		}
	}
	return (NULL);
}

static void	show(struct s_client *client)
{
	if (client == NULL)
		return ;
	if (g_mini.curr_pid != client->pid)
	{
		ft_putstr_fd("\n", 1);
		ft_putstr_fd(BLUE "=================================== ", 1);
		ft_putnbr_fd(client->pid, 1);
		ft_putstr_fd(" ===================================" NC, 1);
		ft_putstr_fd("\n", 1);
		g_mini.curr_pid = client->pid;
	}
}

static void	recv(int pid, int sig)
{
	struct s_client	*client;

	client = get(pid);
	if (client == NULL)
	{
		if (sig == SIGUSR1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		return ;
	}
	client->bit_buf = client->bit_buf << 1 | (sig == SIGUSR1);
	client->bit_len++;
	if (client->bit_len == 8)
	{
		show(client);
		client->buf[client->len++] = client->bit_buf;
		if (client->bit_buf == 0 || client->len == sizeof(client->buf))
		{
			write(1, client->buf, client->len);
			client->use = 0;
		}
		client->bit_len = 0;
	}
	kill(pid, sig);
}

int	main(void)
{
	volatile sig_atomic_t	i;

	init(handler);
	ft_printf("server[%d] start...\n", getpid());
	while (1)
	{
		if (g_mini.cnt == 0)
			continue ;
		i = 0;
		g_mini.lock = 1;
		while (i < g_mini.cnt)
		{
			recv(g_mini.pid[i], g_mini.sig[i]);
			++i;
		}
		g_mini.cnt = 0;
		g_mini.lock = 0;
	}
	exit(EXIT_SUCCESS);
}
