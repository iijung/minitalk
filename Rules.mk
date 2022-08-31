# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Rules.mk                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/29 07:07:52 by minjungk          #+#    #+#              #
#    Updated: 2022/08/31 18:15:06 by minjungk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_ON_ERROR:
.DEFAULT_GOAL := all

CC := cc
AR := ar
RM := rm -f

ARFLAGS = rsc
CFLAGS = -Wall -Wextra -Werror -MMD -MP

ifdef DEBUG
	CFLAGS += -O0 -g -fsanitize=address,undefined
endif

Q = @
ifdef VERBOSE
	Q =
endif

%.o : %.c
	$(Q)$(CC) $(CFLAGS) -c -o $@ $<

# **************************************************************************** #
# function rule 
# **************************************************************************** #
link_files:: unlink_files
	@mkdir -p $(dst_dir);
	$(Q)$(foreach file,$(files), ln -sf $(src_dir)/$(file) $(dst_dir);)

unlink_files::
	$(Q)$(foreach file,$(files), $(RM) $(dst_dir)/$(file);)
