# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/02 13:24:32 by bedarenn          #+#    #+#              #
#    Updated: 2024/07/28 12:14:00 by matde-ol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##################################### NAME #####################################

WATI_HDRS := libwati.h
WATI_NAME := libwati.a
WATI_RULES := wati-

MLX_HDRS := mlx.h
MLX_INT := mlx_int.h
MLX_NAME := libmlx.a
MLX_RULES := mlx-

EXT_RULES := ext-

################################### COMPILER ###################################

CC := cc
# CC := gcc -g --function-sections -Wl,--gc-sections -Wl,--print-gc-sections

################################# DIRECTORIES ##################################

DIR_WATI := libwati/
DIR_MLX := minilibx-linux/

DIR_LIBS := libs/

DIR_SRCS := srcs/
DIR_SRCS_BONUS := srcs_bonus/

DIR := \
	$(DIR_SRCS) \
	$(DIR_HDRS)

#################################### FLAGS #####################################

CFLAGS := -Wall -Wextra -Werror
LFLAGS := -L$(DIR_LIBS) -lwati -lmlx -lXext -lX11 -lm -lz

#################################### FILES #####################################

include $(DIR_SRCS)sources.mk
include $(DIR_SRCS_BONUS)sources.mk

##################################### MAKE #####################################

MAKE := make --no-print-directory -C

#################################### RULES #####################################

all:
bonus:
debug:

$(NAME): $(OBJS)
	@printf "$(GREEN)compile $@                                         $(NC)\n"
	@$(CC) $^ $(LFLAGS) -o $@

$(NAME_BONUS): $(OBJS_BONUS)
	@printf "$(GREEN)compile $@                                         $(NC)\n"
	@$(CC) $^ $(LFLAGS) -o $@

clean: $(EXT_RULES)clean
	@printf "$(RED)clean objs$(NC)\n"
	@rm -rf $(DIR_OBJS) $(DIR_OBJS_BONUS)

fclean: $(EXT_RULES)clean
	@printf "$(RED)clean $(NAME)$(NC)\n"
	@rm -rf $(DIR_OBJS) $(DIR_OBJS_BONUS)
	@rm -f $(NAME) $(NAME_BONUS)

re: fclean all

all:	$(EXT_RULES)all $(NAME)
bonus:	$(EXT_RULES)bonus $(NAME_BONUS)
debug:	CFLAGS += -g
debug:	$(EXT_RULES)debug $(NAME)


################################# EXT_RULES ###################################

$(EXT_RULES)all: $(MLX_RULES)all $(WATI_RULES)all
	@cp $(DIR_WATI)$(WATI_HDRS) $(DIR_HDRS)
	@cp $(DIR_MLX)$(MLX_HDRS) $(DIR_HDRS)$(MLX_HDRS)
	@cp $(DIR_MLX)$(MLX_INT) $(DIR_HDRS)$(MLX_INT)
$(EXT_RULES)bonus: $(MLX_RULES)all $(WATI_RULES)all
	@cp $(DIR_WATI)$(WATI_HDRS) $(DIR_HDRS_BONUS)
	@cp $(DIR_MLX)$(MLX_HDRS) $(DIR_HDRS_BONUS)$(MLX_HDRS)
	@cp $(DIR_MLX)$(MLX_INT) $(DIR_HDRS_BONUS)$(MLX_INT)
$(EXT_RULES)debug: 	$(MLX_RULES)all $(WATI_RULES)debug
	@cp $(DIR_WATI)$(WATI_HDRS) $(DIR_HDRS)
	@cp $(DIR_MLX)$(MLX_HDRS) $(DIR_HDRS)$(MLX_HDRS)
	@cp $(DIR_MLX)$(MLX_INT) $(DIR_HDRS)$(MLX_INT)
$(EXT_RULES)clean: $(MLX_RULES)clean $(WATI_RULES)fclean
$(EXT_RULES)re: $(MLX_RULES)re $(WATI_RULES)re
$(EXT_RULES)git: $(MLX_RULES)git $(WATI_RULES)git

################################# WATI_RULES ###################################

$(WATI_RULES)all: $(WATI_NAME)
$(WATI_NAME):
	@$(MAKE) $(DIR_WATI) -j
	@mkdir -p $(DIR_LIBS)
	@cp $(DIR_WATI)$(WATI_NAME) $(DIR_LIBS)
$(WATI_RULES)debug:
	@$(MAKE) $(DIR_WATI) debug -j
	@cp $(DIR_WATI)$(WATI_NAME) $(DIR_LIBS)
	@cp $(DIR_WATI)$(WATI_HDRS) $(DIR_HDRS)$(WATI_HDRS)
$(WATI_RULES)clean:
	@$(MAKE) $(DIR_WATI) clean
	@rm -f $(DIR_HDRS)$(WATI_HDRS) $(DIR_LIBS)$(WATI_NAME) $(DIR_HDRS_BONUS)$(WATI_HDRS)
$(WATI_RULES)fclean:
	@$(MAKE) $(DIR_WATI) fclean
	@rm -f $(DIR_HDRS)$(WATI_HDRS) $(DIR_LIBS)$(WATI_NAME) $(DIR_HDRS_BONUS)$(WATI_HDRS)
$(WATI_RULES)re:
	@$(MAKE) $(DIR_WATI) re
$(WATI_RULES)git:
	@printf "$(RED)clean $@ $(NC)\n"
	@rm -rf $(DIR_WATI).git

################################# MLX_RULES ###################################

$(MLX_RULES)all: $(MLX_NAME)
$(MLX_NAME):
	@$(MAKE) $(DIR_MLX) -j
	@mkdir -p $(DIR_LIBS)
	@cp $(DIR_MLX)$(MLX_NAME) $(DIR_LIBS)
$(MLX_RULES)clean:
	@$(MAKE) $(DIR_MLX) clean
	@rm -f $(DIR_HDRS)$(MLX_HDRS) $(DIR_HDRS)$(MLX_INT) $(DIR_HDRS_BONUS)$(MLX_HDRS) $(DIR_HDRS_BONUS)$(MLX_INT) $(DIR_LIBS)$(WATI_NAME)
$(MLX_RULES)re:
	@$(MAKE) $(DIR_MLX) re
$(MLX_RULES)git:
	@printf "$(RED)clean $@$(NC)\n"
	@rm -rf $(DIR_MLX).git

#################################### PHONY #####################################
.PHONY: all clean fclean debug dir git

#################################### COLORS ####################################
RED = \033[0;31m
GREEN = \033[0;32m
BROWN = \033[1;33m
PURPLE = \033[0;35m
NC = \033[0m
