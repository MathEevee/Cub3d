/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:06:44 by bedarenn          #+#    #+#             */
/*   Updated: 2024/06/12 17:14:37 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	display(t_pdata pdata, t_info info)
{
	t_coord	pos_map;

	pos_map = set_coord(-info.base.pos.x * SQRT_SIZE
			+ pdata.map->max.x / 2 - SQRT_SIZE / 2,
			-info.base.pos.y * SQRT_SIZE
			+ pdata.map->max.y / 2 - SQRT_SIZE / 2);
	display_minimap(pdata.map, pos_map, info);
	ray_casting(pdata.map, info);
}
