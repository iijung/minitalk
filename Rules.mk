# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Rules.mk                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/29 07:07:52 by minjungk          #+#    #+#              #
#    Updated: 2022/08/30 04:01:40 by minjungk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_GOAL := all

CC := cc
AR := ar
RM := rm -f

ARFLAGS = rsc
CFLAGS = -Wall -Wextra -Werror

ifeq ($(DEBUG), 1)
	CFLAGS += -O0 -g -fsanitize=address,leak,undefined
endif


# **************************************************************************** #
# function rule 
# **************************************************************************** #
link_files:: unlink_files
	@if [ ! -d $(dst_dir) ]; then \
		mkdir -p $(dst_dir); \
	fi;
	@for file in $(files); do \
		ln -sf $(src_dir)/$$files $(dst_dir); \
	done

unlink_files::
	@for file in $(files); do \
		$(RM) $(dst_dir)/$$file; \
	done
