/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 14:25:32 by bedarenn          #+#    #+#             */
/*   Updated: 2024/07/04 15:53:49 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>

#include "cub3d.h"

static void			_ray_casting(t_data *data, t_info info, t_coord map);
static t_ray		ray(t_coord_f player, char **map, t_angle angle);

void	ray_casting(t_data *data, t_info info, t_coord map)
{
	_ray_casting(data, info, map);
}

static void	_ray_casting(t_data *data, t_info info, t_coord map)
{
	t_angle		fov;
	t_angle		alpha;
	t_ray		pxl;
	t_coord		player;
	int			i;

	fov = FOV * (M_PI / 180.0);
	alpha = info.base.angle - fov / 2;
	fov = fov / WIN_X;
	i = 0;
	player = get_pixel_minimap(map, info.base.pos);
	while (i < WIN_X)
	{
		pxl = ray(info.base.pos, info.map, alpha);
		wmlx_put_line(data, player, get_pixel_minimap(map, pxl.pos), 0xff0000);
		alpha += fov;
		i++;
	}
}

static t_ray	ray(t_coord_f player, char **map, t_angle angle)
{
	t_trigo	trig;
	t_ray	x;
	t_ray	y;

	trig.cos = -cosf(angle);
	trig.sin = -sinf(angle);
	x = ray_init_x(player, trig);
	y = ray_init_y(player, trig);
	return (ray_loop(x, y, map));
}
