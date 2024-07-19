/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:06:44 by bedarenn          #+#    #+#             */
/*   Updated: 2024/07/19 10:41:19 by matde-ol         ###   ########.fr       */
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
	ray_casting(pdata, info);
}
