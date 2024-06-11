/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:12:03 by bedarenn          #+#    #+#             */
/*   Updated: 2024/06/11 14:50:33 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	display_map(t_data *data, t_coord base, t_info info)
{
	t_coord	pos;
	char	**strs;
	char	*str;

	pos.y = base.y + SQRT_SIZE / 2;
	strs = info.map;
	while (*strs)
	{
		str = *strs;
		pos.x = base.x + SQRT_SIZE / 2;
		while (*str && *str != '\n')
		{
			if (*str == '0')
				wmlx_put_square(data, pos, SQRT_SIZE, info.color_f);
			else if (*str == '1')
				wmlx_put_square(data, pos, SQRT_SIZE, info.color_c);
			str++;
			pos.x += SQRT_SIZE;
		}
		strs++;
		pos.y += SQRT_SIZE;
	}
}

void	display_minimap(t_data *data, t_info info)
{
	t_coord	pos_map;

	pos_map = set_coord(-info.base.pos.x * SQRT_SIZE + data->max.x / 2
			- SQRT_SIZE / 2, -info.base.pos.y * SQRT_SIZE + data->max.y / 2
			- SQRT_SIZE / 2);
	display_map(data, pos_map, info);
	pos_map = set_coord(data->max.x / 2, data->max.y / 2);
	ray_casting(data, pos_map, info);
	pos_map = set_coord(pos_map.x - PLAYER_SIZE / 2,
			pos_map.y - PLAYER_SIZE / 2);
	wmlx_put_square(data, pos_map, PLAYER_SIZE, 0xff0000);
}
