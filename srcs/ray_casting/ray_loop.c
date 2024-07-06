/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 13:54:57 by bedarenn          #+#    #+#             */
/*   Updated: 2024/07/06 10:23:58 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_ray	ray_loop(t_ray x, t_ray y, char **map)
{
	t_ray	*ray;

	if (x.len < y.len)
		ray = &x;
	else
		ray = &y;
	if (x.len < y.len)
	{
		if (x.i.x < 0)
			x.hit.x--;
	}
	else
	{
		if (y.i.y < 0)
			y.hit.y--;
	}
	while (!check_map(ray->hit, map))
	{
		ray_incr(ray);
		if (x.len < y.len)
		{
			ray = &x;
			if (x.i.x < 0)
				x.hit.x--;
		}
		else
		{
			ray = &y;
			if (y.i.y < 0)
				y.hit.y--;
		}
	}
	return (*ray);
}

