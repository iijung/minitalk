# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/29 06:04:57 by minjungk          #+#    #+#              #
#    Updated: 2022/08/30 04:14:12 by minjungk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include Rules.mk

NAME = minitalk

SERVER = server
CLIENT = client

$(NAME): all
all bonus clean fclean re:
	@$(MAKE) TOPDIR=`pwd` $(MAKECMDGOALS) -C lib
	@$(MAKE) TOPDIR=`pwd` $(MAKECMDGOALS) -C src

$(SERVER):
	@$(MAKE) TOPDIR=`pwd` $(MAKECMDGOALS) -C lib
	@$(MAKE) TOPDIR=`pwd` $(MAKECMDGOALS) -C src/$(SERVER)

$(CLIENT):
	@$(MAKE) TOPDIR=`pwd` $(MAKECMDGOALS) -C lib
	@$(MAKE) TOPDIR=`pwd` $(MAKECMDGOALS) -C src/$(CLIENT)

.PHONY: all clean fclean re bonus
