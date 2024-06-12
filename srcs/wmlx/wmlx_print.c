/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wmlx_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:49:41 by bedarenn          #+#    #+#             */
/*   Updated: 2024/06/10 15:30:52 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <unistd.h>

void	wmlx_put_pixel(t_data *data, t_coord coord, t_color color)
{
	char	*dst;

	if (coord.x >= 0 && coord.x < data->max.x && coord.y >= 0
		&& coord.y < data->max.y)
	{
		dst = data->addr + (coord.y * data->line_length + coord.x
				* (data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	wmlx_put_rect(t_data *data, t_coord begin, t_coord end, t_color color)
{
	t_coord	i;

	i.y = begin.y;
	while (i.y < end.y)
	{
		i.x = begin.x;
		while (i.x < end.x)
		{
			wmlx_put_pixel(data, i, color);
			i.x++;
		}
		i.y++;
	}
}

void	wmlx_put_square(t_data *data, t_coord coord, int size, t_color color)
{
	t_coord	end;

	end.x = coord.x + size;
	end.y = coord.y + size;
	wmlx_put_rect(data, coord, end, color);
}

void	wmlx_put_line(t_data *data, t_coord start, t_coord end, t_color color)
{
	t_coord	delta;
	t_coord	step;
	t_coord	current;
	int		err;
	int		e2;

	delta = set_coord(abs(end.x - start.x), abs(end.y - start.y));
	if (start.x < end.x)
		step.x = 1;
	else
		step.x = -1;
	if (start.y < end.y)
		step.y = 1;
	else
		step.y = -1;
	err = delta.x - delta.y;
	current = start;
	wmlx_put_pixel(data, current, color);
	while (current.x != end.x && current.y != end.y)
	{
		e2 = 2 * err;
		if (e2 > -delta.y)
		{
			err -= delta.y;
			current.x += step.x;
		}
		if (e2 < delta.x)
		{
			err += delta.x;
			current.y += step.y;
		}
		wmlx_put_pixel(data, current, color);
	}
}

void	wmlx_clear_img(t_data *data)
{
	wati_bzero(data->addr, data->max.y * data->line_length + data->max.x
		* (data->bits_per_pixel / 8));
}
