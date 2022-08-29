/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 04:23:34 by minjungk          #+#    #+#             */
/*   Updated: 2022/08/30 08:39:53 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	send_message(pid_t pid, char *msg)
{
	int				ret;
	unsigned char	bit;

	while (msg && *msg)
	{
		bit = 0x01 << 7;
		while (bit)
		{
			if (*msg & bit)
				ret = kill(pid, SIGUSR1);
			else
				ret = kill(pid, SIGUSR2);
			if (ret < 0)
				return (-1);
			bit >>= 1;
		}
		++msg;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_printf("usage: client <server pid> <message>\n");
		return (0);
	}
	ft_printf("client start...\n");
	ft_printf("pid : %d\n", getpid());

	send_message(ft_atoi(argv[1]), argv[2]);

	ft_printf("client stop...\n");
	return (0);
}
