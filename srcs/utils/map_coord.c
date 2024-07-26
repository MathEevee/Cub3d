/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_coord.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 10:19:51 by matde-ol          #+#    #+#             */
/*   Updated: 2024/07/26 11:18:13 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_coord	map_coord(t_map map)
{
	t_coord	size;

	size.x = 0;
	size.y = 0;
	while (map.map[size.y])
	{
		size.x = 0;
		while (map.map[size.y][size.x])
			size.x++;
		size.y++;
	}
	return (size);
}

char	map_getter(t_map map, t_coord coord)
{
	if (coord.x < 0 || coord.y < 0
		|| coord.x >= map.size.x || coord.y >= map.size.y)
		return ('\0');
	return (map.map[coord.x][coord.y]);
}