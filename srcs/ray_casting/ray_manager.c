/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 12:57:02 by bedarenn          #+#    #+#             */
/*   Updated: 2024/07/08 14:31:38 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "cub3d.h"

t_ray	ray_init_x(t_coord_f coord, t_trigo trig)
{
	t_ray		ray;

	ray.pos = coord;
	ray.i_len = wati_abs_f(1 / trig.cos);
	ray.i = set_coord_f(wati_sig_f(trig.cos), trig.sin / wati_abs_f(trig.cos));
	if (trig.cos < 0)
	{
		ray.v.x = -tonext_int(ray.pos.x);
		ray.len = ray.v.x / trig.cos;
		ray.v.y = trig.sin * ray.len;
		ray.dir = 'W';
	}
	else
	{
		ray.v.x = toprev_int(ray.pos.x);
		ray.len = ray.v.x / trig.cos;
		ray.v.y = trig.sin * ray.len;
		ray.dir = 'E';
	}
	ray.hit = cast_to_coord(sum_coord_f(ray.pos, ray.v));
	if (ray.i.x < 0)
		ray.hit.x--;
	return (ray);
}

t_ray	ray_init_y(t_coord_f coord, t_trigo trig)
{
	t_ray		ray;

	ray.pos = coord;
	ray.i_len = wati_abs_f(1 / trig.sin);
	ray.i = set_coord_f(trig.cos / wati_abs_f(trig.sin), wati_sig_f(trig.sin));
	if (trig.sin < 0)
	{
		ray.v.y = -tonext_int(ray.pos.y);
		ray.len = ray.v.y / trig.sin;
		ray.v.x = trig.cos * ray.len;
		ray.dir = 'N';
	}
	else
	{
		ray.v.y = toprev_int(ray.pos.y);
		ray.len = ray.v.y / trig.sin;
		ray.v.x = trig.cos * ray.len;
		ray.dir = 'S';
	}
	ray.hit = cast_to_coord(sum_coord_f(ray.pos, ray.v));
	if (ray.i.y < 0)
		ray.hit.y--;
	return (ray);
}

void	ray_incr(t_ray *ray)
{
	ray->v = sum_coord_f(ray->v, ray->i);
	ray->len += ray->i_len;
	ray->hit = cast_to_coord(sum_coord_f(ray->pos, ray->v));
}

t_float	toprev_int(t_float nb)
{
	if (nb > 0)
		nb = ((int)nb + 1) - nb;
	else
		nb = ((int)nb - 1) + nb;
	return (nb);
}

t_float	tonext_int(t_float nb)
{
	if (nb > 0)
		nb = nb - (int)nb;
	else
		nb = nb + (int)nb;
	return (nb);
}
