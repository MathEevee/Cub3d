/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 12:57:02 by bedarenn          #+#    #+#             */
/*   Updated: 2024/07/04 15:51:49 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>

#include "cub3d.h"

t_ray	ray_init_x(t_coord_f coord, t_trigo trig)
{
	t_ray		ray;
	t_coord_f	i;

	ray.pos = coord;
	ray.i_len = wati_abs_f(1 / trig.cos);
	ray.i = set_coord_f(wati_sig_f(trig.cos), trig.sin / wati_abs_f(trig.cos));
	if (trig.cos < 0)
	{
		i.x = -tonext_int(ray.pos.x);
		ray.len = i.x / trig.cos;
		i.y = trig.sin * ray.len;
	}
	else
	{
		i.x = toprev_int(ray.pos.x);
		ray.len = i.x / trig.cos;
		i.y = trig.sin * ray.len;
	}
	ray.pos.x += i.x;
	ray.pos.y += i.y;
	ray.hit = cast_to_coord(ray.pos);
	return (ray);
}

t_ray	ray_init_y(t_coord_f coord, t_trigo trig)
{
	t_ray		ray;
	t_coord_f	i;

	ray.pos = coord;
	ray.i_len = wati_abs_f(1 / trig.sin);
	ray.i = set_coord_f(trig.cos / wati_abs_f(trig.sin), wati_sig_f(trig.sin));
	if (trig.sin < 0)
	{
		i.y = -tonext_int(ray.pos.y);
		ray.len = i.y / trig.sin;
		i.x = trig.cos * ray.len;
	}
	else
	{
		i.y = toprev_int(ray.pos.y);
		ray.len = i.y / trig.sin;
		i.x = trig.cos * ray.len;
	}
	ray.pos.x += i.x;
	ray.pos.y += i.y;
	ray.hit = cast_to_coord(ray.pos);
	return (ray);
}

void	ray_incr(t_ray *ray)
{
	ray->pos.x += ray->i.x;
	ray->pos.y += ray->i.y;
	ray->len += ray->i_len;
	ray->hit = cast_to_coord(ray->pos);
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
