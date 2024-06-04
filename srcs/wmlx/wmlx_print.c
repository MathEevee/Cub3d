/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wmlx_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:49:41 by bedarenn          #+#    #+#             */
/*   Updated: 2024/06/04 15:34:01 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	wmlx_update_win(t_mlx mlx)
{
	mlx_put_image_to_window(mlx.ptr, mlx.win, mlx.img.img, 0, 0);
}

void	wmlx_put_pixel(t_data *data, t_coord coord, int color)
{
	char	*dst;

	if (coord.x >= 0 && coord.x < WIN_X
		&& coord.y >= 0 && coord.y < WIN_Y)
	{
		dst = data->addr + (coord.y * data->line_length
				+ coord.x * (data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	wmlx_put_rect(t_data *data, t_coord begin, t_coord end, int color)
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
