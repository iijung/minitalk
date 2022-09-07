/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 04:23:34 by minjungk          #+#    #+#             */
/*   Updated: 2022/09/07 11:26:06 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static t_socket	*head;

static unsigned char	*add_byte(unsigned char	*dst, unsigned char c)
{
	char	*old;
	size_t	olen;

	old = dst;
	olen = 0;
	if (old)
		olen = ft_strlen(old);
	dst = ft_calloc(olen + 1 + 1, sizeof(unsigned char));
	if (dst)
	{
		ft_memcpy(dst, old, olen);
		dst[olen] = c;
	}
	free(old);
	return (dst);
}

static void	recv(siginfo_t *info, int bit)
{
	t_socket		*curr;

	if (info == 0)
		return ;
	curr = search_socket(info->si_pid);
	if (curr == 0)
		return ;
	curr->read_buf = (curr->read_buf << 1) | bit;
	curr->read_bit++;
	if (curr->read_bit == 8)
	{
		curr->read_bit = 0;
		if (curr->message == 0)
			curr->message = ft_strdup(buf);
		else if (curr->buf)
			curr->message = add_byte(curr->message, curr->buf);
		else
		{
			ft_printf("client[%d] : %s\n", curr->pid, curr->message);
			clear_socket(curr->pid);
		}
		if (curr && curr->message == 0)
			clear_socket(curr->pid);
	}
}

static void	handler(int sig, siginfo_t *info, void *ucontext)
{
	(void)ucontext;
	if (info == 0)
		return ;
	if (sig == SIGUSR1 || sig == SIGUSR2)
	{
		recv(info, sig == SIGUSR1);
	}
	else
	{
		ft_putstr_fd("Invalid Signal\n", 2);
		clear_socket(0);
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
	clear_socket(0);
	ft_printf("server[%d] stop...\n", getpid());
	return (0);
}
