/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:32:24 by matde-ol          #+#    #+#             */
/*   Updated: 2024/07/08 13:42:27 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/cub3d.h"

void	init_player(t_info *info, int x, int y, t_angle radiant)
{
	info->base.pos.x = x;
	info->base.pos.y = y;
	info->base.angle = radiant;
	if (info->map != NULL)
	{
		info->map[y][x] = '0';
		info->base.pos.x += 0.5;
		info->base.pos.y += 0.5;
	}
}

void	init_info(t_info *info)
{
	info->map = NULL;
	info->img_no.img = NULL;
	info->img_so.img = NULL;
	info->img_we.img = NULL;
	info->img_ea.img = NULL;
	init_player(info, -1, -1, -1);
	info->color_f = -1;
	info->color_c = -1;
}
