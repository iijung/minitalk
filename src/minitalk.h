/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 04:27:25 by minjungk          #+#    #+#             */
/*   Updated: 2022/09/07 01:08:29 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
//# include <stdlib.h>
//# include <unistd.h>
# include <signal.h>
# include "ft_printf.h"

typedef struct s_socket
{
	int				pid;
	int				read_bit;
	unsigned char	read_buf;
	unsigned char	*message;
	struct s_socket	*next;
}				t_socket;

t_socket	*search_socket(int pid);
void		 clear_socket(int pid);
#endif
