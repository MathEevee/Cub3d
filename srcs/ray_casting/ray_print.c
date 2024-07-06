/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 10:33:07 by bedarenn          #+#    #+#             */
/*   Updated: 2024/07/06 18:45:58 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>

#include "cub3d.h"

static t_color	choose_color(char dir);

void	ray_print(t_data *data, t_info info, t_ray ray, int i)
{
	t_color	color;
	int		size;
	int		j;
	t_range	val;

	color = choose_color(ray.dir);
	j = 0;
	size = data->max.y / ray.len;
	val.min = (data->max.y / 2) - (size / 2);
	val.max = (data->max.y / 2) + (size / 2);
	while (j < data->max.y)
	{
		if (j < val.min)
			wmlx_put_pixel(data, set_coord(i, j), info.color_c);
		else if (j < val.max)
			wmlx_put_pixel(data, set_coord(i, j), color);
		else
			wmlx_put_pixel(data, set_coord(i, j), info.color_f);
		j++;
	}
}

static t_color	choose_color(char dir)
{
	if (dir == 'S')
		return (0x00ff0000);
	if (dir == 'N')
		return (0x00ffff00);
	if (dir == 'W')
		return (0x0000ff00);
	if (dir == 'E')
		return (0x000000ff);
	return (0x0);
}
