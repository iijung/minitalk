# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/30 02:49:12 by minjungk          #+#    #+#              #
#    Updated: 2022/08/30 17:49:42 by minjungk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifndef $(TOPDIR)
	TOPDIR = ..
endif
include $(TOPDIR)/Rules.mk

NAME =

$(NAME): all
all bonus clean fclean re:
	$(MAKE) TOPDIR=$(TOPDIR) $(MAKECMDGOALS) -C libft
	$(MAKE) TOPDIR=$(TOPDIR) $(MAKECMDGOALS) -C ftprintf

.PHONY: all clean fclean re bonus
