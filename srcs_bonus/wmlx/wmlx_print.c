/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wmlx_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:49:41 by bedarenn          #+#    #+#             */
/*   Updated: 2024/07/22 11:39:29 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./hdrs_bonus/cub3d.h"

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

void	wmlx_clear_img(t_data *data)
{
	wati_bzero(data->addr, data->max.y * data->line_length + data->max.x
		* (data->bits_per_pixel / 8));
}
