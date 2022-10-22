# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjungk <minjungk@student.42seoul.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/04 20:07:19 by minjungk          #+#    #+#              #
#    Updated: 2022/10/23 00:34:36 by minjungk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifndef TOPDIR
	TOPDIR = $(abspath ../..)
endif
include $(TOPDIR)/Rules.mk

NAME = libft.a

HEAD = \
	libft.h \

OBJS = \
	ft_isalpha.o \
	ft_isdigit.o \
	ft_isalnum.o \
	ft_isascii.o \
	ft_isprint.o \
	ft_strlen.o \
	ft_memset.o \
	ft_bzero.o \
	ft_memcpy.o \
	ft_memmove.o \
	ft_strlcpy.o \
	ft_strlcat.o \
	ft_toupper.o \
	ft_tolower.o \
	ft_strchr.o \
	ft_strrchr.o \
	ft_strncmp.o \
	ft_memchr.o \
	ft_memcmp.o \
	ft_strnstr.o \
	ft_atoi.o \
	ft_calloc.o \
	ft_strdup.o \
	ft_substr.o \
	ft_strjoin.o \
	ft_strtrim.o \
	ft_split.o \
	ft_itoa.o \
	ft_utoa.o \
	ft_strmapi.o \
	ft_striteri.o \
	ft_putchar_fd.o \
	ft_putstr_fd.o \
	ft_putendl_fd.o \
	ft_putnbr_fd.o \
	ft_lstnew.o \
	ft_lstadd_front.o \
	ft_lstsize.o \
	ft_lstlast.o \
	ft_lstadd_back.o \
	ft_lstdelone.o \
	ft_lstclear.o \
	ft_lstiter.o \
	ft_lstmap.o \
	ft_lstmap.o \
	get_next_line.o \

DEPS = $(OBJS:.o=.d)
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
