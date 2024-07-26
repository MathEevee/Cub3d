/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bool.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 11:37:12 by bedarenn          #+#    #+#             */
/*   Updated: 2024/07/26 14:51:59 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	check_map(t_map map, t_coord hit)
{
	return (map_getter(map, hit) == '1');
}

bool	check_map_convert(t_coord_f hit, char **map)
{
	return (map[(int)hit.y][(int)hit.x] == '1');
}
