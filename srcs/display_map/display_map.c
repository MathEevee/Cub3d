/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:12:03 by bedarenn          #+#    #+#             */
/*   Updated: 2024/06/12 15:33:17 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

void	display_map(t_data *data, t_coord base, t_info info)
{
	t_coord	pos;
	char	**strs;
	char	*str;

	pos.y = base.y + SQRT_SIZE / 2;
	strs = info.map;
	while (*strs)
	{
		str = *strs;
		pos.x = base.x + SQRT_SIZE;
		while (*str && *str != '\n')
		{
			if (*str == '0')
				wmlx_put_square(data, pos, SQRT_SIZE, info.color_f);
			else if (*str == '1')
				wmlx_put_square(data, pos, SQRT_SIZE, info.color_c);
			str++;
			pos.x += SQRT_SIZE;
		}
		strs++;
		pos.y += SQRT_SIZE;
	}
	printf("base.x = %d | base.y = %d\n", base.x, base.y);
	printf("pos.x = %d | pos.y = %d\n", pos.x, pos.y);
}

// void	display_map(t_data *data, t_coord base, t_info info)
// {
// 	t_coord	pos;
// 	t_coord	nbr_sqrt;
// 	t_coord	count;
// 	// char	**strs;
// 	// char	*str;

// 	(void) info;
// 	nbr_sqrt.y = data->max.y / SQRT_SIZE;
// 	nbr_sqrt.x = data->max.x / SQRT_SIZE;
// 	pos.y = base.y + SQRT_SIZE / 2;
// 	// strs = info.map;
// 	count.y = 0;
// 	printf("base.x / SQRT_SIZE = %d | base.y /SQRT_SIZE = %d\n", base.x / SQRT_SIZE,base.y / SQRT_SIZE);
// 	printf("data->max.x = %d | data->max.y = %d\n", data->max.x,data->max.y);
// 	// printf("data->max.x = %d | data->max.y = %d\n", data->max.x,data->max.y);
// 	printf("pos.x = %d | pos.y = %d\n", pos.x,pos.y);
// 	// printf("data->max.x = %d | data->max.y = %d\n", data->max.x,data->max.y);
// 	// while (count.y != nbr_sqrt.y)
// 	// {
// 	// }
// }

void	display_minimap(t_data *data, t_info info)
{
	t_coord	player;

	player = set_coord(-info.base.pos.x * SQRT_SIZE + data->max.x / 2
			- SQRT_SIZE / 2, -info.base.pos.y * SQRT_SIZE + data->max.y / 2
			- SQRT_SIZE / 2);
	display_map(data, player, info);
	player = set_coord(data->max.x / 2, data->max.y / 2);
	ray_casting(data, player, info);
	player = set_coord(player.x - PLAYER_SIZE / 2, player.y - PLAYER_SIZE / 2);
	wmlx_put_square(data, player, PLAYER_SIZE, 0xff0000);
}
