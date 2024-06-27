/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_incr_first.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:31:56 by bedarenn          #+#    #+#             */
/*   Updated: 2024/06/27 11:19:19 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>

#include "cub3d.h"

t_float	get_distance_inter_cos(t_coord_f *coord, t_trigo trig);
t_float	get_distance_inter_sin(t_coord_f *coord, t_trigo trig);
t_float	toprev_int(t_float nb);
t_float	tonext_int(t_float nb);

t_coord_f	first_incr(t_coord_f pxl, t_angle angle)
{
	t_trigo		trig;
	t_coord_f	next;
	t_coord_f	_cos;
	t_coord_f	_sin;

	trig.cos = -cos(angle);
	trig.sin = -sin(angle);
	_cos = pxl;
	_sin = pxl;
	next.x = get_distance_inter_cos(&_cos, trig);
	next.y = get_distance_inter_sin(&_sin, trig);
	if (wati_abs_f(next.x) < wati_abs_f(next.y))
	{
		pxl.x += _cos.x;
		pxl.y += _cos.y;
	}
	else
	{
		pxl.x += _sin.x;
		pxl.y += _sin.y;
	}
	return (pxl);
}

t_float	get_distance_inter_cos(t_coord_f *coord, t_trigo trig)
{
	t_float	h;

	if (trig.cos > 0)
	{
		coord->x = toprev_int(coord->x);
		h = coord->x / trig.cos;
		coord->y = trig.sin * h;
	}
	else if (trig.cos < 0)
	{
		coord->x = -tonext_int(coord->x);
		h = coord->x / trig.cos;
		coord->y = trig.sin * h;
	}
	else
		h = 0;
	return (h);
}

t_float	get_distance_inter_sin(t_coord_f *coord, t_trigo trig)
{
	t_float	h;

	if (trig.sin > 0)
	{
		coord->y = toprev_int(coord->y);
		h = coord->y / trig.sin;
		coord->x = trig.cos * h;
	}
	else if (trig.sin < 0)
	{
		coord->y = -tonext_int(coord->y);
		h = coord->y / trig.sin;
		coord->x = trig.cos * h;
	}
	else
		h = 0;
	return (h);
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
