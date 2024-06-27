/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 14:25:32 by bedarenn          #+#    #+#             */
/*   Updated: 2024/06/26 15:45:51 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>

#include "cub3d.h"

static void			_ray_casting(t_data *data, t_info info, t_coord map);
static t_coord_f	ray(t_info info, t_angle angle);
static t_coord_f	incr_to_next(t_coord_f pxl, t_angle angle);

void	ray_casting(t_data *data, t_info info, t_coord map)
{
	_ray_casting(data, info, map);
}

static void	_ray_casting(t_data *data, t_info info, t_coord map)
{
	t_angle		fov;
	t_angle		alpha;
	t_coord_f	pxl;
	t_coord		player;
	int			i;

	fov = FOV * (M_PI / 180.0);
	alpha = info.base.angle - fov / 2;
	fov = fov / WIN_X;
	i = 0;
	player = get_pixel_minimap(map, info.base.pos);
	// while (i < WIN_X)
	// {
	// 	pxl = ray(info, alpha);
	// 	wmlx_put_line(data, player, get_pixel_minimap(map, pxl), 0xff0000);
	// 	alpha += fov;
	// 	i++;
	// }
	pxl = ray(info, info.base.angle);
	wmlx_put_line(data, player, get_pixel_minimap(map, pxl), 0xff0000);
}

static t_coord_f	ray(t_info info, t_angle angle)
{
	t_coord_f	pxl;

	pxl = info.base.pos;
	pxl = first_incr(pxl, angle);
	incr_to_next(pxl, angle);
	return (pxl);
}

static t_coord_f	incr_to_next(t_coord_f pxl, t_angle angle)
{
	pxl.x -= cos(angle);
	pxl.y -= sin(angle);
	return (pxl);
}
