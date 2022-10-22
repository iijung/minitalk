# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/30 02:49:12 by minjungk          #+#    #+#              #
#    Updated: 2022/10/23 00:29:26 by minjungk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifndef TOPDIR
	TOPDIR = $(abspath ..)
endif
include $(TOPDIR)/Rules.mk

LIBS = libft/libft.a ftprintf/ftprintf.a

all bonus clean fclean re:
	@for dir in $(dir $(LIBS)); do \
		$(MAKE) TOPDIR=$(TOPDIR) -C $$dir $@; \
	done

.PHONY: all clean fclean re bonus
