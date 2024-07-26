/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 12:57:02 by bedarenn          #+#    #+#             */
/*   Updated: 2024/07/26 11:58:21 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "cub3d.h"

t_ray_cast	ray_init_x(t_coord_f coord, t_trigo trig)
{
	t_ray_cast	ray;

	ray.r.pos = coord;
	ray.i.len = wati_abs_f(1 / trig.cos);
	ray.i.i = set_coord_f(wati_sig_f(trig.cos),
			trig.sin / wati_abs_f(trig.cos));
	if (trig.cos < 0)
	{
		ray.r.dir = 'E';
		ray.r.vect.x = -tonext_int(ray.r.pos.x);
		ray.r.len = ray.r.vect.x / trig.cos;
		ray.r.vect.y = trig.sin * ray.r.len;
	}
	else
	{
		ray.r.dir = 'W';
		ray.r.vect.x = toprev_int(ray.r.pos.x);
		ray.r.len = ray.r.vect.x / trig.cos;
		ray.r.vect.y = trig.sin * ray.r.len;
	}
	ray.i.hit = cast_to_coord(sum_coord_f(ray.r.pos, ray.r.vect));
	if (ray.i.i.x < 0)
		ray.i.hit.x--;
	return (ray);
}

t_ray_cast	ray_init_y(t_coord_f coord, t_trigo trig)
{
	t_ray_cast	ray;

	ray.r.pos = coord;
	ray.i.len = wati_abs_f(1 / trig.sin);
	ray.i.i = set_coord_f(trig.cos / wati_abs_f(trig.sin),
			wati_sig_f(trig.sin));
	if (trig.sin < 0)
	{
		ray.r.dir = 'S';
		ray.r.vect.y = -tonext_int(ray.r.pos.y);
		ray.r.len = ray.r.vect.y / trig.sin;
		ray.r.vect.x = trig.cos * ray.r.len;
	}
	else
	{
		ray.r.dir = 'N';
		ray.r.vect.y = toprev_int(ray.r.pos.y);
		ray.r.len = ray.r.vect.y / trig.sin;
		ray.r.vect.x = trig.cos * ray.r.len;
	}
	ray.i.hit = cast_to_coord(sum_coord_f(ray.r.pos, ray.r.vect));
	if (ray.i.i.y < 0)
		ray.i.hit.y--;
	return (ray);
}

void	ray_incr(t_ray_cast *ray, t_ray_cast *x, t_ray_cast *y)
{
	t_coord_f	pos;

	ray->r.vect = sum_coord_f(ray->r.vect, ray->i.i);
	ray->r.len += ray->i.len;
	if (ray == x)
	{
		pos = sum_coord_f(ray->r.pos, ray->r.vect);
		pos.x = roundf(pos.x);
		ray->i.hit = cast_to_coord(pos);
		if (ray->i.i.x < 0)
			ray->i.hit.x--;
	}
	if (ray == y)
	{
		pos = sum_coord_f(ray->r.pos, ray->r.vect);
		pos.y = roundf(pos.y);
		ray->i.hit = cast_to_coord(pos);
		if (ray->i.i.y < 0)
			ray->i.hit.y--;
	}
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
