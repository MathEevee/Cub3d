/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wmlx_put_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 10:33:40 by bedarenn          #+#    #+#             */
/*   Updated: 2024/07/08 14:03:45 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_color	wmlx_get_pixel(t_data *data, t_coord coord)
{
	char	*dst;

	if (coord.x < 0 && coord.x >= data->max.x && coord.y < 0
		&& coord.y >= data->max.y)
		return (0x0);
	dst = data->addr + (coord.y * data->line_length + coord.x
			* (data->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

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

static void	_wmlx_put_line(t_coord	*d, t_coord	*s, t_coord start, t_coord end);

void	wmlx_put_line(t_data *data, t_coord start, t_coord end, t_color color)
{
	t_coord	d;
	t_coord	s;
	int		err;
	int		e2;

	_wmlx_put_line(&d, &s, start, end);
	err = d.x + d.y;
	while (1)
	{
		wmlx_put_pixel(data, start, color);
		if (start.x == end.x && start.y == end.y)
			break ;
		e2 = 2 * err;
		if (e2 >= d.y)
		{
			err += d.y;
			start.x += s.x;
		}
		if (e2 <= d.x)
		{
			err += d.x;
			start.y += s.y;
		}
	}
}

static void	_wmlx_put_line(t_coord	*d, t_coord	*s, t_coord start, t_coord end)
{
	*d = set_coord(wati_abs(end.x - start.x), -wati_abs(end.y - start.y));
	if (start.x < end.x)
		(*s).x = 1;
	else
		(*s).x = -1;
	if (start.y < end.y)
		(*s).y = 1;
	else
		(*s).y = -1;
}
