/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 01:06:51 by minjungk          #+#    #+#             */
/*   Updated: 2022/09/07 17:19:29 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_socket	*search_socket(t_socket **head, int pid)
{
	t_socket	*curr;
	t_socket	*new;

	if (head == 0)
		return (0);
	curr = *head;
	while (curr)
	{
		if (curr->pid == pid)
			return (curr);
		if (curr->next == 0)
			break ;
		curr = curr->next;
	}
	new = ft_calloc(1, sizeof(t_socket));
	if (new == 0)
		return (0);
	new->pid = pid;
	if (curr)
		curr->next = new;
	else
		*head = new;
	return (new);
}

void	clear_socket(t_socket **head, int pid)
{
	t_socket	*prev;
	t_socket	*curr;
	t_socket	*next;

	if (head == 0)
		return ;
	prev = 0;
	curr = *head;
	while (curr)
	{
		if (pid == 0 || pid == curr->pid)
		{
			next = curr->next;
			free(curr->message);
			free(curr);
			if (prev)
				prev->next = next;
			else
				*head = next;
			if (pid)
				return ;
		}
		prev = curr;
		curr = curr->next;
	}
}
