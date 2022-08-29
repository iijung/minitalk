/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 04:23:34 by minjungk          #+#    #+#             */
/*   Updated: 2022/08/30 08:15:58 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

//int	sig_handler1(int sig, siginfo_t *info, void *ucontext)

int	main(void)
{
//	int					sig;
//	struct sigaction	act;

	ft_printf("server start...\n");
	ft_printf("pid : %d\n", getpid());

#if 0
	sigemptyset(&(act.sa_mask));
	sigaddset(&(act.sa_mask), SIGUSR1);

	act.sa_handler = NULL;
	act.sa_sigaction = sig_handler1;
	act.sa_flags = SA_SIGINFO;

	if (sigaction(SIGUSR1, &act, NULL) < 0)
		return (-1);

	while (1)
	{
		sig = pause();
		if (sig < 0)
			return (-1);

	}
#endif
	ft_printf("server stop...\n");
	return (0);
}
