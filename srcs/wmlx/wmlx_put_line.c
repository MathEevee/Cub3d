/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wmlx_put_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 10:33:40 by bedarenn          #+#    #+#             */
/*   Updated: 2024/07/26 15:43:04 by matde-ol         ###   ########.fr       */
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
