/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 04:27:25 by minjungk          #+#    #+#             */
/*   Updated: 2022/11/14 00:03:51 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <signal.h>
# include "ft_printf.h"

# define NC			"\x1B[0m"
# define BLACK		"\x1B[0;30m"
# define RED		"\x1B[0;31m"
# define GREEN		"\x1B[0;32m"
# define YELLO		"\x1B[0;33m"
# define BLUE		"\x1B[0;34m"
# define MAGENTA	"\x1B[0;35m"
# define CYAN		"\x1B[0;36m"
# define WHITE		"\x1B[0;37m"
# define BG_BLACK	"\x1B[0;40m"
# define BG_RED		"\x1B[0;41m"
# define BG_GREEN	"\x1B[0;42m"
# define BG_YELLO	"\x1B[0;43m"
# define BG_BLUE	"\x1B[0;44m"
# define BG_MAGENTA	"\x1B[0;45m"
# define BG_CYAN	"\x1B[0;46m"
# define BG_WHITE	"\x1B[0;47m"

# define MAXQ		64

struct s_client
{
	int		use;
	int		pid;
	int		bit_len;
	char	bit_buf;
	int		len;
	char	buf[1024];
};

typedef struct s_minitalk	t_minitalk;

struct s_minitalk
{
	volatile sig_atomic_t	lock;
	volatile sig_atomic_t	cnt;
	volatile sig_atomic_t	sig[MAXQ];
	volatile sig_atomic_t	pid[MAXQ];
	volatile sig_atomic_t	curr_pid;
	struct s_client			client[MAXQ];
};

extern struct s_minitalk	g_mini;

void	init(void *handler);

#endif
