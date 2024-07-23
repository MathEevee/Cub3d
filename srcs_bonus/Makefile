# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bedarenn <bedarenn@student.42angouleme.fr> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/02 13:24:32 by bedarenn          #+#    #+#              #
#    Updated: 2024/07/23 15:20:48 by bedarenn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################### COMPILER ###################################
# CC := gcc -g --function-sections -Wl,--gc-sections -Wl,--print-gc-sections

CC := cc

################################# DIRECTORIES ##################################

DIR_OBJS := ../objs/

DIR_HDRS := hdrs/
DIR := \
	$(DIR_SRCS) \
	$(DIR_HDRS)

#################################### FILES #####################################

include sources.mk

OBJS = $(addprefix $(DIR_OBJS), $(SRCS_BONUS:%.c=%.o))

#################################### FLAGS #####################################

CFLAGS := -Wall -Wextra -Werror
IFLAGS := -I../$(DIR_HDRS)

#################################### RULES #####################################

all:
debug:

$(DIR_OBJS)%.o: %.c
	@printf "$(BROWN)compile $(notdir $<)                              $(NC) \r"
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

all:	$(OBJS)
debug:	CFLAGS += -g
debug:	$(OBJS)

dir: $(DIR)
	mkdir -p $^

#################################### PHONY #####################################
.PHONY: all clean fclean debug dir git

#################################### COLORS ####################################
RED = \033[0;31m
GREEN = \033[0;32m
BROWN = \033[1;33m
PURPLE = \033[0;35m
NC = \033[0m
