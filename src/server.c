/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 04:23:34 by minjungk          #+#    #+#             */
/*   Updated: 2022/09/08 07:50:20 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static t_socket	*g_head;

static char	*add_byte(char	*dst, char c)
{
	char	*old;
	size_t	olen;

	old = dst;
	olen = 0;
	if (old)
		olen = ft_strlen(old);
	dst = ft_calloc(olen + 1 + 1, sizeof(char));
	if (dst)
	{
		ft_memcpy(dst, old, olen);
		dst[olen] = c;
	}
	free(old);
	return (dst);
}

static int	recv(siginfo_t *info, int bit)
{
	t_socket		*curr;

	if (info == 0)
		return (-1);
	curr = search_socket(&g_head, info->si_pid);
	if (curr == 0)
		return (-1);
	curr->read_bit++;
	curr->read_buf = (curr->read_buf << 1) | bit;
	if (curr->read_bit == 8)
	{
		curr->read_bit = 0;
		if (curr->read_buf)
			curr->message = add_byte(curr->message, curr->read_buf);
		else
		{
			ft_printf("client[%d] : %s\n", curr->pid, curr->message);
			return (1);
		}
		if (curr->message == 0)
			return (-2);
	}
	return (0);
}

static void	handler(int sig, siginfo_t *info, void *ucontext)
{
	int	ret;

	(void)ucontext;
	if (info == 0)
		return ;
	if (sig == SIGUSR1 || sig == SIGUSR2)
	{
		ret = recv(info, sig == SIGUSR1);
		if (ret != 0)
			clear_socket(&g_head, info->si_pid);
		if (ret < 0)
			kill(info->si_pid, SIGUSR2);
		else
			kill(info->si_pid, SIGUSR1);
	}
	else
	{
		ft_putstr_fd("invalid signal\n", 2);
		clear_socket(&g_head, info->si_pid);
	}
}

int	main(void)
{
	struct sigaction	act;

	sigemptyset(&act.sa_mask);
	sigaddset(&act.sa_mask, SIGUSR1);
	sigaddset(&act.sa_mask, SIGUSR2);
	act.sa_handler = 0;
	act.sa_sigaction = handler;
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, 0);
	sigaction(SIGUSR2, &act, 0);
	ft_printf("server[%d] start...\n", getpid());
	while (1)
		pause();
	clear_socket(&g_head, 0);
	ft_printf("server[%d] stop...\n", getpid());
	return (0);
}
