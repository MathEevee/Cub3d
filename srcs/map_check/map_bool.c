/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bool.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 11:37:12 by bedarenn          #+#    #+#             */
/*   Updated: 2024/07/06 20:00:49 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	check_map(t_coord hit, char **map)
{
	return (map[hit.y][hit.x] == '1');
}

bool	check_map_convert(t_coord_f hit, char **map)
{
	return (map[(int)hit.y][(int)hit.x] == '1');
}
