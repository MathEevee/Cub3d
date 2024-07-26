/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 13:54:57 by bedarenn          #+#    #+#             */
/*   Updated: 2024/07/26 12:06:26 by matde-ol         ###   ########.fr       */
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
	ray->r.pos = sum_coord_f(ray->r.pos, ray->r.vect);
	return (ray->r);
}
