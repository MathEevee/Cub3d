/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_cub3d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 15:07:11 by matde-ol          #+#    #+#             */
/*   Updated: 2024/07/08 13:54:33 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "cub3d.h"

void	print_col_wall_coord(t_info *info)
{
	int	y;
	int	x;

	y = info->base.pos.y;
	x = info->base.pos.x;
	while (info->map[y][x] != '1')
	{
		if (info->base.angle == M_PI_2)
			y--;
		if (info->base.angle == M_PI)
			x--;
		if (info->base.angle == -M_PI_2)
			y++;
		if (info->base.angle == 0)
			x++;
	}
}

void	begin_cub3d(int fd, t_joe_mama *var)
{
	char		**file;

	init_info(&var->info);
	file = format_fd_no_nl(fd);
	if (file == NULL)
	{
		wati_fprintf(2, "This file is empty\nError\n");
		return ;
	}
	if (set_info(file, var) == -1)
	{
		//addfree
		return ;
	}
	wati_free_tab(file);
	if (map_checker(&var->info) == true)
	{
		wmlx_loop_draw(var);
		wmlx_update_win(var->mlx);
		wkey_init_hook(var);
		mlx_loop(var->mlx.ptr);
		free_mlx(var->mlx.ptr, &var->info);
		wmlx_destroy(var->mlx);
		wati_free_tab(var->info.map);
		// start_game();
	}
	// freeall dans tous les cas
}
