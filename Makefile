# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/29 06:04:57 by minjungk          #+#    #+#              #
#    Updated: 2022/10/22 05:15:05 by minjungk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include Rules.mk

SERVER = server
CLIENT = client

all bonus clean fclean re:
	$Q$(MAKE) TOPDIR=`pwd` -C lib $@
	$Q$(MAKE) TOPDIR=`pwd` -C src $@

$(SERVER) $(CLIENT):
	$Q$(MAKE) TOPDIR=`pwd` -C lib
	$Q$(MAKE) TOPDIR=`pwd` -C src $@

.PHONY: all clean fclean re bonus $(SERVER) $(CLIENT)
