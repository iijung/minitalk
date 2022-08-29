# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/30 02:29:01 by minjungk          #+#    #+#              #
#    Updated: 2022/08/30 04:12:16 by minjungk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include $(TOPDIR)/Rules.mk

NAME =

SERVER = server
CLIENT = client

$(NAME): all
all bonus clean fclean re: $(SERVER) $(CLIENT)

$(SERVER):
#	$(MAKE) TOPDIR=$(TOPDIR) $(MAKECMDGOALS) -C $(SERVER)

$(CLIENT):
#	$(MAKE) TOPDIR=$(TOPDIR) $(MAKECMDGOALS) -C $(CLIENT)

.PHONY: all clean fclean re bonus server client
