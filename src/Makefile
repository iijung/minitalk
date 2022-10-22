# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/30 02:29:01 by minjungk          #+#    #+#              #
#    Updated: 2022/10/22 05:14:56 by minjungk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifndef TOPDIR
	TOPDIR = $(abspath ..)
endif
include $(TOPDIR)/Rules.mk

SERVER = server
CLIENT = client

all bonus clean fclean re:
	$Q$(MAKE) TOPDIR=$(TOPDIR) -f Makefile.$(SERVER) $@
	$Q$(MAKE) TOPDIR=$(TOPDIR) -f Makefile.$(CLIENT) $@

$(SERVER) $(CLIENT):
	$(MAKE) TOPDIR=$(TOPDIR) -f Makefile.$@

.PHONY: all clean fclean re bonus $(SERVER) $(CLIENT)
