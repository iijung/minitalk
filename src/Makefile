# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/30 02:29:01 by minjungk          #+#    #+#              #
#    Updated: 2022/08/31 04:35:48 by minjungk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifndef TOPDIR
	TOPDIR = $(abspath ..)
endif
include $(TOPDIR)/Rules.mk

CFLAGS += -I$(TOPDIR)/include
LDFLAGS = -L$(TOPDIR)/lib -lftprintf -lft

HEAD = minitalk.h

SERVER = server
CLIENT = client

all bonus:
	@$(MAKE) files=$(HEAD) src_dir=`pwd` dst_dir=$(TOPDIR)/include link_files
	@$(MAKE) -f Makefile.$(SERVER) TOPDIR=$(TOPDIR) $@
	@$(MAKE) -f Makefile.$(CLIENT) TOPDIR=$(TOPDIR) $@

$(SERVER):
	@$(MAKE) -f Makefile.$@ $(MAKECMDGOALS)

$(CLIENT):
	@$(MAKE) -f Makefile.$@ $(MAKECMDGOALS)

clean:
	@$(MAKE) files=$(HEAD) src_dir=`pwd` dst_dir=$(TOPDIR)/include unlink_files
	@$(MAKE) -f Makefile.$(SERVER) TOPDIR=$(TOPDIR) clean
	@$(MAKE) -f Makefile.$(CLIENT) TOPDIR=$(TOPDIR) clean

fclean: clean
	@$(MAKE) -f Makefile.$(SERVER) TOPDIR=$(TOPDIR) fclean
	@$(MAKE) -f Makefile.$(CLIENT) TOPDIR=$(TOPDIR) fclean

re: fclean
	@$(MAKE) $(if $(filter bonus, $(MAKCMDGOALS)), bonus, all)

.PHONY: all clean fclean re bonus
