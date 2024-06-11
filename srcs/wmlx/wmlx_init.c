/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wmlx_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:20:34 by bedarenn          #+#    #+#             */
/*   Updated: 2024/06/11 15:28:42 by bedarenn         ###   ########.fr       */
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
	mlx.img.win = wmlx_init_img(mlx.ptr, WIN_X, WIN_Y);
	mlx.img.map = wmlx_init_img(mlx.ptr, MAP_X, MAP_Y);
	mlx.pimg.win = &mlx.img.win;
	mlx.pimg.map = &mlx.img.map;
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

void	wmlx_destroy(t_mlx mlx)
{
	mlx_destroy_image(mlx.ptr, mlx.img.win.img);
	mlx_destroy_image(mlx.ptr, mlx.img.map.img);
	mlx_destroy_window(mlx.ptr, mlx.win);
	mlx_destroy_display(mlx.ptr);
	free(mlx.ptr);
}
