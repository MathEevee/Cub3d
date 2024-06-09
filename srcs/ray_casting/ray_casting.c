/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 14:25:32 by bedarenn          #+#    #+#             */
/*   Updated: 2024/06/09 15:37:58 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "cub3d.h"

// int	dist_wall(t_coord player, char **map, double angle)
// {
// 	int		dist;
// 	float	a;
// 	float	b;
// 	float	delta_a;
// 	float	delta_b;

// 	if (angle >= PI / 2 || angle <= 0)
// 		return (100);
// 	a = player.y - (int) player.y;
// 	b = player.x - (int) player.x;
// 	delta_a = 50 / tan(angle);
// 	delta_b = tan(angle) * 50;
// 	return (200);
// }

void	ray(t_data *data, double angle, t_coord player)
{
	t_coord	pxl;
	int		i;
	// int		dist;

	i = 0;
	// dist = dist_wall(player, map, angle);
	while (i < 100)
	{
		pxl.x = player.x - (int)(i * cos(angle));
		pxl.y = player.y - (int)(i * sin(angle));
		wmlx_put_pixel(data, pxl, 0xff8080);
		i++;
	}
}

void	ray_casting(t_data *data, t_coord player, t_info info)
{
	double	fov;
	double	begin;
	double	incr;
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
