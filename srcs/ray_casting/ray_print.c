/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 10:33:07 by bedarenn          #+#    #+#             */
/*   Updated: 2024/07/09 14:13:57 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>

#include "cub3d.h"

static t_float	choose_img(t_info *info, t_data **img, t_ray ray);
static t_color	choose_pixel(t_data *data, t_float x, t_float y);

static t_color	choose_color(char dir);

void	ray_print(t_data *data, t_info info, t_ray ray, int i)
{
	t_data	*img;
	t_float	x;
	t_color	color;
	int		size;
	int		j;
	t_range	val;

	j = 0;
	size = data->max.y / ray.len;
	val.min = (data->max.y / 2) - (size / 2);
	val.max = (data->max.y / 2) + (size / 2);
	x = choose_img(&info, &img, ray);
	while (j < data->max.y)
	{
		if (j < val.min)
			wmlx_put_pixel(data, set_coord(i, j), info.color_c);
		else if (j >= val.max)
			wmlx_put_pixel(data, set_coord(i, j), info.color_f);
		else
		{
			color = choose_pixel(img, x, (j - (t_float)val.min) / (t_float)(val.max - val.min));
			wmlx_put_pixel(data, set_coord(i, j), color);
		}
		j++;
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
