/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 04:45:14 by minjungk          #+#    #+#             */
/*   Updated: 2022/10/23 01:41:31 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	parse_tokens(int fd, t_list *lst, va_list ap)
{
	int		len;
	int		total;
	t_token	*token;

	total = 0;
	while (lst && lst->content)
	{
		token = lst->content;
		if (ft_parse_token(token, ap) < 0 || token->out == 0)
			return (-1);
		if (token->width == 0)
			token->width = ft_strlen(token->out);
		len = write(fd, token->out, token->width);
		if (len < 0)
			return (-1);
		total += len;
		lst = lst->next;
	}
	return (total);
}

int	ft_printf(const char *format, ...)
{
	t_list	*head;
	int		total;
	va_list	ap;

	head = 0;
	total = 0;
	if (format == 0 || format[0] == 0)
		return (0);
	va_start(ap, format);
	total = ft_make_tokens(&head, format);
	if (total == 0)
		total = parse_tokens(1, head, ap);
	ft_lstclear(&head, ft_free_token);
	va_end(ap);
	return (total);
}

int	ft_printf_fd(int fd, const char *format, ...)
{
	t_list	*head;
	int		total;
	va_list	ap;

	head = 0;
	total = 0;
	if (format == 0 || format[0] == 0)
		return (0);
	va_start(ap, format);
	total = ft_make_tokens(&head, format);
	if (total == 0)
		total = parse_tokens(fd, head, ap);
	ft_lstclear(&head, ft_free_token);
	va_end(ap);
	return (total);
}
