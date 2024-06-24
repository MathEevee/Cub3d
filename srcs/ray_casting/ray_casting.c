/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 14:25:32 by bedarenn          #+#    #+#             */
/*   Updated: 2024/06/12 17:34:35 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "cub3d.h"

void	ray(t_data *data, t_angle angle, t_coord player);
void	_ray_casting(t_data *data, t_coord player, t_info info);

void	ray_casting(t_data *data, t_info info)
{
	_ray_casting(data, set_coord(data->max.x / 2, data->max.y / 2), info);
}

void	_ray_casting(t_data *data, t_coord player, t_info info)
{
	t_angle	fov;
	t_angle	begin;
	t_angle	incr;
	int		i;

	fov = FOV * (PI / 180.0);
	begin = info.base.angle - fov / 2;
	incr = fov / WIN_X;
	i = 0;
	while (i < WIN_X)
	{
		ray(data, begin, player);
		begin += incr;
		i++;
	}
}

void	ray(t_data *data, t_angle angle, t_coord player)
{
	t_coord	pxl;
	int		i;

	i = 0;
	while (i < 100)
	{
		pxl.x = player.x - (int)(i * cos(angle));
		pxl.y = player.y - (int)(i * sin(angle));
		wmlx_put_pixel(data, pxl, 0xff8080);
		i++;
	}
}
