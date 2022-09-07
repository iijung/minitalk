/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 04:27:25 by minjungk          #+#    #+#             */
/*   Updated: 2022/09/08 07:49:13 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <signal.h>
# include "ft_printf.h"

typedef struct s_socket
{
	int					pid;
	int					read_bit;
	char				read_buf;
	char				*message;
	struct s_socket		*next;
}				t_socket;

t_socket	*search_socket(t_socket **head, int pid);
void		clear_socket(t_socket **head, int pid);
#endif
