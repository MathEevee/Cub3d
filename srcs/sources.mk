# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    sources.mk                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bedarenn <bedarenn@student.42angouleme.fr> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/23 14:40:44 by bedarenn          #+#    #+#              #
#    Updated: 2024/07/23 15:31:34 by bedarenn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DIR_OBJS := objs/

SRCS = \
	struct_manager/coord_manager.c \
	parsing/path_register.c \
	parsing/check_color.c \
	parsing/init_struct.c \
	parsing/check_img.c \
	register_fd/register_data.c \
	register_fd/format_fd.c \
	register_fd/start_cub3d.c \
	map_check/check_map_params.c \
	map_check/map_border.c \
	map_check/map_bool.c \
	utils/cpy_tab.c \
	utils/map_coord.c \
	clear/free_img.c \
	clear/free_var.c \
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
	ray_casting/ray_print.c \
	display/display.c \
	display/display_map.c \
	main.c
