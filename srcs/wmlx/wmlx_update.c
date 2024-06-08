/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wmlx_update.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 12:39:20 by bedarenn          #+#    #+#             */
/*   Updated: 2024/06/08 14:46:10 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	wmlx_loop_draw(t_joe_mama *var)
{
	wmlx_clear_img(&var->mlx.i_win);
	wmlx_clear_img(&var->mlx.i_map);
	if (var->mode == MODE_MAIN)
		display_minimap(&var->mlx.i_map, var->info);
	else if (var->mode == MODE_MINIMAP)
		display_minimap(&var->mlx.i_win, var->info);
}

void	wmlx_update_win(t_mlx mlx)
{
	t_coord	map_place;

	mlx_put_image_to_window(mlx.ptr, mlx.win, mlx.i_win.img, 0, 0);
	map_place = set_coord(mlx.i_win.max.x - mlx.i_map.max.x - MAP_MARGE,
			MAP_MARGE);
	mlx_put_image_to_window(mlx.ptr, mlx.win, mlx.i_map.img, map_place.x,
		map_place.y);
}
