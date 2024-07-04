# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bedarenn <bedarenn@student.42angouleme.fr> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/02 13:24:32 by bedarenn          #+#    #+#              #
#    Updated: 2024/07/04 15:51:56 by bedarenn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##################################### NAME #####################################
NAME := cub3d

WATI_HDRS := libwati.h
WATI_NAME := libwati.a
WATI_RULES := wati-

MLX_HDRS := mlx.h
MLX_INT := mlx_int.h
MLX_NAME := libmlx.a
MLX_RULES := mlx-

EXT_RULES := ext-

################################### COMPILER ###################################
CC := clang

################################# DIRECTORIES ##################################

DIR_OBJS := objs/
DIR_WATI := libwati/
DIR_MLX := minilibx-linux/
DIR_LIBS := libs/

DIR_SRCS := srcs/
DIR_HDRS := hdrs/
DIR := \
	$(DIR_SRCS) \
	$(DIR_HDRS)

#################################### FILES #####################################

SRCS = \
	struct_manager/coord_manager.c \
	parsing/path_register.c \
	parsing/init_struct.c \
	register_fd/register_data.c \
	register_fd/format_fd.c \
	register_fd/start_cub3d.c \
	map_check/check_map_params.c \
	map_check/map_border.c \
	map_check/map_bool.c \
	utils/cpy_tab.c \
	clear/free_img.c \
	struct_manager/key_manager.c \
	struct_manager/joe_mama_manager.c \
	struct_manager/tv_manager.c \
	wmlx/wmlx_init.c \
	wmlx/wkey_hook.c \
	wmlx/wmlx_loop.c \
	wmlx/wmlx_print.c \
	wmlx/wmlx_update.c \
	wmlx/wmlx_put_line.c \
	ray_casting/ray_casting.c \
	ray_casting/ray_loop.c \
	ray_casting/ray_manager.c \
	display/display.c \
	display/display_map.c \
	main.c
OBJS = $(addprefix $(DIR_OBJS), $(SRCS:%.c=%.o))

#################################### FLAGS #####################################
CFLAGS := -Wall -Wextra #-Werror
LFLAGS := -L$(DIR_LIBS) -lwati -lmlx -lXext -lX11 -lm -lz
IFLAGS := -I$(DIR_HDRS)

##################################### MAKE #####################################
MAKE := make --no-print-directory -C

#################################### RULES #####################################

debug:
all:

$(NAME): $(OBJS)
	@printf "$(GREEN)compile $@                                         $(NC)\n"
	@$(CC) $^ $(LFLAGS) -o $@

$(DIR_OBJS)%.o: $(DIR_SRCS)%.c
	@printf "$(BROWN)compile $(notdir $<)                              $(NC) \r"
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean: $(EXT_RULES)clean
	@printf "$(RED)clean objs$(NC)\n"
	@rm -rf $(DIR_OBJS)

fclean: $(EXT_RULES)clean
	@printf "$(RED)clean $(NAME)$(NC)\n"
	@rm -rf $(DIR_OBJS)
	@rm -f $(NAME)

re: fclean debug

all:	$(MLX_NAME) $(WATI_NAME) $(NAME)
debug:	CFLAGS += -g
debug:	$(EXT_RULES)debug $(NAME)

dir: $(DIR)
	mkdir -p $^

################################# EXT_RULES ###################################

$(EXT_RULES)all: $(MLX_RULES)all $(WATI_RULES)all
$(EXT_RULES)debug: 	$(MLX_RULES)all $(WATI_RULES)debug
$(EXT_RULES)clean: $(MLX_RULES)clean $(WATI_RULES)fclean
$(EXT_RULES)re: $(MLX_RULES)re $(WATI_RULES)re
$(EXT_RULES)git: $(MLX_RULES)git $(WATI_RULES)git

################################# WATI_RULES ###################################

$(WATI_RULES)all: $(WATI_NAME)
$(WATI_NAME):
	@$(MAKE) $(DIR_SRCS)$(DIR_WATI) -j
	@mkdir -p $(DIR_LIBS)
	@cp $(DIR_SRCS)$(DIR_WATI)$(WATI_NAME) $(DIR_LIBS)
	@cp $(DIR_SRCS)$(DIR_WATI)$(WATI_HDRS) $(DIR_HDRS)
$(WATI_RULES)debug:
	@$(MAKE) $(DIR_SRCS)$(DIR_WATI) debug -j
	@cp $(DIR_SRCS)$(DIR_WATI)$(WATI_NAME) $(DIR_LIBS)
	@cp $(DIR_SRCS)$(DIR_WATI)$(WATI_HDRS) $(DIR_HDRS)$(WATI_HDRS)
$(WATI_RULES)clean:
	@$(MAKE) $(DIR_SRCS)$(DIR_WATI) clean
$(WATI_RULES)fclean:
	@$(MAKE) $(DIR_SRCS)$(DIR_WATI) fclean
	@rm -f $(DIR_HDRS)$(WATI_HDRS) $(DIR_LIBS)$(WATI_NAME)
$(WATI_RULES)re:
	@$(MAKE) $(DIR_SRCS)$(DIR_WATI) re
$(WATI_RULES)git:
	@printf "$(RED)clean $@ $(NC)\n"
	@rm -rf $(DIR_SRCS)$(DIR_WATI).git

################################# MLX_RULES ###################################

$(MLX_RULES)all: $(MLX_NAME)
$(MLX_NAME):
	@$(MAKE) $(DIR_SRCS)$(DIR_MLX) -j
	@mkdir -p $(DIR_LIBS)
	@cp $(DIR_SRCS)$(DIR_MLX)$(MLX_NAME) $(DIR_LIBS)
	@cp $(DIR_SRCS)$(DIR_MLX)$(MLX_HDRS) $(DIR_HDRS)$(MLX_HDRS)
	@cp $(DIR_SRCS)$(DIR_MLX)$(MLX_INT) $(DIR_HDRS)$(MLX_INT)
$(MLX_RULES)clean:
	@$(MAKE) $(DIR_SRCS)$(DIR_MLX) clean
	@rm -f $(DIR_HDRS)$(MLX_HDRS) $(DIR_HDRS)$(MLX_INT) $(DIR_LIBS)$(WATI_NAME)
$(MLX_RULES)re:
	@$(MAKE) $(DIR_SRCS)$(DIR_MLX) re
$(MLX_RULES)git:
	@printf "$(RED)clean $@$(NC)\n"
	@rm -rf $(DIR_SRCS)$(DIR_MLX).git

#################################### PHONY #####################################
.PHONY: all clean fclean debug dir git

#################################### COLORS ####################################
RED = \033[0;31m
GREEN = \033[0;32m
BROWN = \033[1;33m
PURPLE = \033[0;35m
NC = \033[0m
