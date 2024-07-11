/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 10:33:07 by bedarenn          #+#    #+#             */
/*   Updated: 2024/07/11 15:07:12 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>

#include "cub3d.h"

static t_float	choose_img(t_info *info, t_data **img, t_ray ray);
static t_color	choose_pixel(t_data *data, t_float x, t_float y);

void	ray_print(t_data *data, t_info info, t_ray ray, t_float wall)
{
	t_data	*img;
	t_float	x;
	int		size;
	t_range	val;

	x = choose_img(&info, &img, ray);
	size = wall / ray.len;
	val.min = (data->max.y / 2) - (size / 2);
	val.max = (data->max.y / 2) + (size / 2);
	ray.screen.y = 0;
	while (ray.screen.y < data->max.y)
	{
		if (ray.screen.y < val.min)
			wmlx_put_pixel(data, ray.screen, info.color_c);
		else if (ray.screen.y >= val.max)
			wmlx_put_pixel(data, ray.screen, info.color_f);
		else
		{
			wmlx_put_pixel(data, ray.screen,
				choose_pixel(img, x,
					(ray.screen.y - (t_float)val.min) / (t_float)size));
		}
		ray.screen.y++;
	}
}

static t_float	choose_img(t_info *info, t_data **img, t_ray ray)
{
	if (ray.dir == 'S')
	{
		*img = &info->img_so;
		return (wati_abs_f(ray.pos.x) - wati_abs(floorf(ray.pos.x)));
	}
	else if (ray.dir == 'N')
	{
		*img = &info->img_no;
		return (wati_abs_f(ray.pos.x) - wati_abs(floorf(ray.pos.x)));
	}
	else if (ray.dir == 'W')
	{
		*img = &info->img_we;
		return (wati_abs_f(ray.pos.y) - wati_abs(floorf(ray.pos.y)));
	}
	else if (ray.dir == 'E')
	{
		*img = &info->img_ea;
		return (wati_abs_f(ray.pos.y) - wati_abs(floorf(ray.pos.y)));
	}
	*img = NULL;
	return (0.0);
}

static	t_color	choose_pixel(t_data *data, t_float x, t_float y)
{
	return (wmlx_get_pixel(data, set_coord(x * data->max.x, y * data->max.y)));
}
