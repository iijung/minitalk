# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Rules.mk                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/29 07:07:52 by minjungk          #+#    #+#              #
#    Updated: 2022/08/31 04:29:07 by minjungk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_ON_ERROR:
.DEFAULT_GOAL := all

CC := cc
AR := ar
RM := rm -f

ARFLAGS = rsc
CFLAGS = -Wall -Wextra -Werror

ifdef DEBUG
	CFLAGS += -O0 -g -fsanitize=address,undefined
endif


# **************************************************************************** #
# function rule 
# **************************************************************************** #
link_files:: unlink_files
	@mkdir -p $(dst_dir);
	$(foreach file,$(files), ln -sf $(src_dir)/$(file) $(dst_dir);)

unlink_files::
	$(foreach file,$(files), $(RM) $(dst_dir)/$(file);)
