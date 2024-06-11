/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:12:03 by bedarenn          #+#    #+#             */
/*   Updated: 2024/06/11 16:51:34 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void	display_map(t_data *data, t_coord base, t_info info)
// {
// 	t_coord	pos;
// 	char	**strs;
// 	char	*str;

// 	pos.y = base.y + SQRT_SIZE / 2;
// 	strs = info.map;
// 	while (*strs)
// 	{
// 		str = *strs;
// 		pos.x = base.x + SQRT_SIZE / 2;
// 		while (*str && *str != '\n')
// 		{
// 			if (*str == '0')
// 				wmlx_put_square(data, pos, SQRT_SIZE, info.color_f);
// 			else if (*str == '1')
// 				wmlx_put_square(data, pos, SQRT_SIZE, info.color_c);
// 			str++;
// 			pos.x += SQRT_SIZE;
// 		}
// 		strs++;
// 		pos.y += SQRT_SIZE;
// 	}
// }

void	display_map(t_data *data, t_coord base, t_info info)
{
	t_coord	pos;
	t_coord	nbr_sqrt;
	t_coord	count;
	char	**strs;
	char	*str;

	nbr_sqrt.y = base.x - data->max.y / SQRT_SIZE;
	nbr_sqrt.x = base.y - data->max.x / SQRT_SIZE;
	pos.y = base.y + SQRT_SIZE / 2;
	strs = info.map;
	count.y = 0;
	printf("nbr_sqrt.y = %d\n", nbr_sqrt.y);
	printf("nbr_sqrt.x = %d\n", nbr_sqrt.x);
	while (count.y != nbr_sqrt.y)
	{
		str = *strs;
		pos.x = base.x + SQRT_SIZE / 2;
		count.x = 0;
		while (count.x != nbr_sqrt.x)
		{
			if (*str == '0')
				wmlx_put_square(data, pos, SQRT_SIZE, info.color_f);
			else if (*str == '1')
				wmlx_put_square(data, pos, SQRT_SIZE, info.color_c);
			str++;
			pos.x += SQRT_SIZE;
			count.x++;
			// printf("x = %d\n", count.x);
		}
		strs++;
		count.y++;
		pos.y += SQRT_SIZE;
	printf("y = %d\n", count.y);
	}
	printf("y = %d\n", count.y);
}

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
