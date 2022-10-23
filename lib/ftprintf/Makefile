# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjungk <minjungk@student.42seoul.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/17 03:49:45 by minjungk          #+#    #+#              #
#    Updated: 2022/10/24 02:05:43 by minjungk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifndef TOPDIR
	TOPDIR = $(abspath ../..)
endif
include $(TOPDIR)/Rules.mk

CFLAGS += -I$(TOPDIR)/include

NAME = libftprintf.a

HEAD = \
	ft_printf.h \

SRCS = \
	ft_make_token.c \
	ft_parse_token.c \
	ft_printf.c \

OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)
-include $(DEPS)

all bonus: $(NAME)

$(NAME): $(OBJS)
	$Q$(AR) $(ARFLAGS) $@ $^ 
	$Q$(MAKE) files=$(NAME) src_dir=`pwd` dst_dir=$(TOPDIR)/lib link_files
	$Q$(MAKE) files=$(HEAD) src_dir=`pwd` dst_dir=$(TOPDIR)/include link_files

clean:
	$Q$(MAKE) files=$(NAME) src_dir=`pwd` dst_dir=$(TOPDIR)/lib unlink_files
	$Q$(MAKE) files=$(HEAD) src_dir=`pwd` dst_dir=$(TOPDIR)/include unlink_files
	$Q$(RM) $(OBJS) $(DEPS)

fclean: clean
	$Q$(RM) $(NAME)

re: fclean
	$Q$(MAKE) all

.PHONY: all clean fclean re bonus
