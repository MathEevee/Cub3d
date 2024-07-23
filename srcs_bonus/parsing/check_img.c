/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 09:30:09 by matde-ol          #+#    #+#             */
/*   Updated: 2024/07/23 15:20:04 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libwati.h"
#include "cub3d.h"

static bool	check_size(t_coord coord, int *i)
{
	while ((*i) <= 2048)
	{
		if (coord.x == (*i) && coord.y == (*i))
			return (true);
		(*i) *= 2;
	}
	return (false);
}

int	check_img(t_joe_mama *var)
{
	int	i;

	i = 2;
	if (check_size(var->info.img_no.max, &i) == false)
		return (-1);
	if (!(var->info.img_so.max.x == var->info.img_so.max.y
			&& var->info.img_so.max.x == i)
		&& (var->info.img_ea.max.x == var->info.img_ea.max.y
			&& var->info.img_ea.max.x == i)
		&& (var->info.img_we.max.x == var->info.img_we.max.y
			&& var->info.img_we.max.x == i))
		return (-1);
	return (0);
}
