/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 13:54:57 by bedarenn          #+#    #+#             */
/*   Updated: 2024/07/11 14:30:39 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "cub3d.h"

t_ray	ray_loop(t_ray_cast x, t_ray_cast y, char **map)
{
	t_ray_cast	*ray;

	if (x.r.len < y.r.len)
		ray = &x;
	else
		ray = &y;
	while (!check_map(ray->i.hit, map))
	{
		ray_incr(ray, &x, &y);
		if (x.r.len < y.r.len)
			ray = &x;
		else
			ray = &y;
	}
	return (ray->r);
}
