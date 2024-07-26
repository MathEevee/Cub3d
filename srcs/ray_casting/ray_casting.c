/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 14:25:32 by bedarenn          #+#    #+#             */
/*   Updated: 2024/07/26 11:54:09 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "cub3d.h"

static t_ray	ray(t_coord_f player, t_map map, t_angle angle);

void	ray_casting(t_pdata pdata, t_info info)
{
	t_ray_alpha	angle;
	t_float		wall;
	int			i;
	t_ray		pxl;

	angle.fov = FOV * (M_PI / 180.0);
	wall = pdata.win->max.x / angle.fov;
	angle.alpha = (angle.fov + M_PI) / 2;
	angle.o_base = 2 * cosf(angle.alpha) / sinf(angle.alpha);
	angle.incr = 2 * angle.o_base / pdata.win->max.x;
	i = 0;
	while (i < pdata.win->max.x)
	{
		angle.alpha = atanf((angle.o_base - i * (angle.incr)) / 2)
			+ M_PI_4 - angle.fov / 2 + info.base.angle;
		pxl = ray(info.base.pos, info.map, angle.alpha);
		pxl.len *= cosf(info.base.angle - angle.alpha);
		pxl.screen.x = i;
		ray_print(pdata.win, info, pxl, wall);
		i++;
	}
}

static t_ray	ray(t_coord_f player, t_map map, t_angle angle)
{
	t_trigo		trig;
	t_ray_cast	x;
	t_ray_cast	y;

	trig.cos = -cosf(angle);
	trig.sin = -sinf(angle);
	x = ray_init_x(player, trig);
	y = ray_init_y(player, trig);
	return (ray_loop(x, y, map));
}
