# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjungk <minjungk@student.42seoul.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/04 20:07:19 by minjungk          #+#    #+#              #
#    Updated: 2022/10/24 02:05:06 by minjungk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifndef TOPDIR
	TOPDIR = $(abspath ../..)
endif
include $(TOPDIR)/Rules.mk

NAME = libft.a

HEAD = \
	libft.h \

SRCS = \
	ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_strlen.c \
	ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strncmp.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strnstr.c \
	ft_atoi.c \
	ft_calloc.c \
	ft_strdup.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_split.c \
	ft_itoa.c \
	ft_utoa.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_lstnew.c \
	ft_lstadd_front.c \
	ft_lstsize.c \
	ft_lstlast.c \
	ft_lstadd_back.c \
	ft_lstdelone.c \
	ft_lstclear.c \
	ft_lstiter.c \
	ft_lstmap.c \
	ft_lstmap.c \
	get_next_line.c \

OBJS = $(SRCS:.c=.c)
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
