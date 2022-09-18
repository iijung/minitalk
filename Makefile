# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/29 06:04:57 by minjungk          #+#    #+#              #
#    Updated: 2022/08/30 21:37:17 by minjungk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include Rules.mk

SERVER = server
CLIENT = client

all bonus clean fclean re:
	@$(MAKE) TOPDIR=`pwd` $(filter $@, $(MAKECMDGOALS)) -C lib
	@$(MAKE) TOPDIR=`pwd` $@ -C src

$(SERVER) $(CLIENT):
	@$(MAKE) TOPDIR=`pwd` -C lib
	@$(MAKE) TOPDIR=`pwd` $@ -C src

.PHONY: all clean fclean re bonus $(SERVER) $(CLIENT)
