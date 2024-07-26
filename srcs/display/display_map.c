/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:12:03 by bedarenn          #+#    #+#             */
/*   Updated: 2024/07/26 14:51:40 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	display_map(t_data *data, t_coord base, t_coord_part part, t_info info)
{
	t_coord			pos;
	t_tab_str_incr	i;

	pos.y = base.y + SQRT_SIZE / 2 + part.min.y * SQRT_SIZE;
	i.strs = info.map.map;
	while (*i.strs && i.strs < info.map.map + part.min.y)
		i.strs++;
	while (*i.strs && i.strs < info.map.map + part.max.y)
	{
		pos.x = base.x + SQRT_SIZE / 2 + part.min.x * SQRT_SIZE;
		i.str = *i.strs;
		while (*i.str && i.str < *i.strs + part.min.x)
			i.str++;
		while (*i.str && i.str < *i.strs + part.max.x)
		{
			if (*i.str == '0')
				wmlx_put_square(data, pos, SQRT_SIZE, info.color_f);
			else if (*i.str == '1')
				wmlx_put_square(data, pos, SQRT_SIZE, info.color_c);
			i.str++;
			pos.x += SQRT_SIZE;
		}
		i.strs++;
		pos.y += SQRT_SIZE;
	}
}

t_coord_part	map_coord_part(t_coord img_max, t_coord_f player)
{
	t_coord			max;
	t_coord_part	part;

	max = set_coord(img_max.x / SQRT_SIZE + 4, img_max.y / SQRT_SIZE + 4);
	part.min = set_coord(player.x - max.x / 2, player.y - max.y / 2);
	if (part.min.x < 0)
		part.min.x = 0;
	if (part.min.y < 0)
		part.min.y = 0;
	part.max = set_coord(player.x + max.x / 2, player.y + max.y / 2);
	return (part);
}
