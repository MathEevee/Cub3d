/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wmlx_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:49:41 by bedarenn          #+#    #+#             */
/*   Updated: 2024/06/05 15:07:30 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "cub3d.h"

void	wmlx_update_win(t_mlx mlx)
{
	t_coord	map_place;

	mlx_put_image_to_window(mlx.ptr, mlx.win, mlx.i_win.img, 0, 0);
	map_place = set_coord(mlx.i_win.max.x - mlx.i_map.max.x
			- (0.05 * mlx.i_win.max.y),
			0.05 * mlx.i_win.max.y);
	mlx_put_image_to_window(mlx.ptr, mlx.win, mlx.i_map.img,
		map_place.x, map_place.y);
}

void	wmlx_put_pixel(t_data *data, t_coord coord, t_color color)
{
	char	*dst;

	if (coord.x >= 0 && coord.x < data->max.x
		&& coord.y >= 0 && coord.y < data->max.y)
	{
		dst = data->addr + (coord.y * data->line_length
				+ coord.x * (data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	wmlx_put_rect(t_data *data, t_coord begin, t_coord end, t_color color)
{
	t_coord	i;
	t_coord	incr;

	if (begin.y < end.y)
		incr.y = 1;
	else
		incr.y = -1;
	if (begin.x < end.x)
		incr.x = 1;
	else
		incr.x = -1;
	i.y = begin.y;
	while (i.y != end.y)
	{
		i.x = begin.x;
		while (i.x != end.x)
		{
			wmlx_put_pixel(data, i, color);
			i.x += incr.x;
		}
		i.y += incr.y;
	}
}

void	wmlx_put_square(t_data *data, t_coord coord, int size, t_color color)
{
	t_coord	end;

	end.x = coord.x + size;
	end.y = coord.y + size;
	wmlx_put_rect(data, coord, end, color);
}
