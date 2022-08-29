# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/30 02:29:01 by minjungk          #+#    #+#              #
#    Updated: 2022/08/30 08:30:49 by minjungk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifndef $(TOPDIR)
	TOPDIR = ..
endif
include $(TOPDIR)/Rules.mk

CFLAGS += -I$(TOPDIR)/include
LDFLAGS = -L$(TOPDIR)/lib -lftprintf -lft

HEAD = minitalk.h

NAME =

# **************************************************************************** #
# server
# **************************************************************************** #
SERVER = server

SERVER_SRCS = \
	server.c \

SERVER_SRCB = \
	server.c \

SERVER_OBJS = $(SERVER_SRC:.c=.o)

$(SERVER): $(if $(filter bonus, $(MAKCMDGOALS)), $(SERVER_SRCB), $(SERVER_SRCS))
	$(CC) $(CFLAGS) $(OUTPUT_OPTION) $^ $(LDFLAGS)
	$(MAKE) files=$(SERVER) src_dir=`pwd` dst_dir=$(TOPDIR) link_files
	$(MAKE) files=$(HEAD) src_dir=`pwd` dst_dir=$(TOPDIR)/include link_files

# **************************************************************************** #
# client
# **************************************************************************** #
CLIENT = client

CLIENT_SRCS = \
	client.c \

CLIENT_SRCB = \
	client.c \

CLIENT_OBJS = $(CLIENT_SRC:.c=.o)

$(CLIENT): $(if $(filter bonus, $(MAKCMDGOALS)), $(CLIENT_SRCB), $(CLIENT_SRCS))
	$(CC) $(CFLAGS) $(OUTPUT_OPTION) $^ $(LDFLAGS)
	$(MAKE) files=$(CLIENT) src_dir=`pwd` dst_dir=$(TOPDIR) link_files
	$(MAKE) files=$(HEAD) src_dir=`pwd` dst_dir=$(TOPDIR)/include link_files

# **************************************************************************** #
$(NAME): all
all bonus: $(SERVER) $(CLIENT)

clean:
	$(MAKE) files=$(SERVER) src_dir=`pwd` dst_dir=$(TOPDIR) unlink_files
	$(MAKE) files=$(CLIENT) src_dir=`pwd` dst_dir=$(TOPDIR) unlink_files
	$(MAKE) files=$(HEAD) src_dir=`pwd` dst_dir=$(TOPDIR)/include unlink_files
	$(RM) $(SERVER_OBJS) $(CLIENT_OBJS)

fclean: clean
	$(RM) $(SERVER) $(CLIENT)

re: fclean
	$(MAKE) $(if $(filter bonus, $(MAKCMDGOALS)), bonus, all)

.PHONY: all clean fclean re bonus server client
