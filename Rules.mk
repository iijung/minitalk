# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Rules.mk                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/29 07:07:52 by minjungk          #+#    #+#              #
#    Updated: 2022/08/31 00:41:39 by minjungk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_ON_ERROR:
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
	@mkdir -p $(dst_dir);
	$(foreach file,$(files), ln -sf $(src_dir)/$(file) $(dst_dir))

unlink_files::
	$(foreach file,$(files), $(RM) $(dst_dir)/$(file))
