/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_coord.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 10:19:51 by matde-ol          #+#    #+#             */
/*   Updated: 2024/07/26 10:54:30 by matde-ol         ###   ########.fr       */
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
