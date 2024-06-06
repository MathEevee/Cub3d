/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wmlx_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:20:34 by bedarenn          #+#    #+#             */
/*   Updated: 2024/06/05 16:21:03 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "cub3d.h"
#include "mlx.h"

t_mlx	wmlx_init(void)
{
	t_mlx	mlx;

	mlx.ptr = mlx_init();
	mlx.win = mlx_new_window(mlx.ptr, WIN_X, WIN_Y, WIN_N);
	mlx.i_win = wmlx_init_img(mlx.ptr, WIN_X, WIN_Y);
	mlx.i_map = wmlx_init_img(mlx.ptr, MAP_X, MAP_Y);
	return (mlx);
}

t_data	wmlx_init_img(t_wptr ptr, int x, int y)
{
	t_data	data;

	data.img = mlx_new_image(ptr, x, y);
	data.addr = mlx_get_data_addr(
			data.img, &data.bits_per_pixel,
			&data.line_length, &data.endian);
	data.max = set_coord(x, y);
	return (data);
}

int	wmlx_destroy(t_joe_mama *var)
{
	wmlx_free_exit(var, EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

void	wmlx_free_exit(t_joe_mama *var, int code)
{
	mlx_destroy_image(var->mlx.ptr, var->mlx.i_win.img);
	mlx_destroy_image(var->mlx.ptr, var->mlx.i_map.img);
	mlx_destroy_window(var->mlx.ptr, var->mlx.win);
	mlx_destroy_display(var->mlx.ptr);
	free(var->mlx.ptr);
	wati_free_tab(var->info.map);
	exit(code);
}
