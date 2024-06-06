/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:12:03 by bedarenn          #+#    #+#             */
/*   Updated: 2024/06/06 10:10:15 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define SQRT_SIZE 50

void	display_map(t_data *data, t_info info)
{
	t_coord	pos;
	char	**strs;
	char	*str;

	pos.y = 0;
	strs = info.map;
	while (*strs)
	{
		str = *strs;
		pos.x = 0;
		while (*str && *str != '\n')
		{
			if (*str == '0')
				wmlx_put_square(data, pos, SQRT_SIZE, info.color_f);
			else
				wmlx_put_square(data, pos, SQRT_SIZE, info.color_c);
			str++;
			pos.x += SQRT_SIZE;
		}
		strs++;
		pos.y += SQRT_SIZE;
	}
}
