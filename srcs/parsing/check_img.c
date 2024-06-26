/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 09:30:09 by matde-ol          #+#    #+#             */
/*   Updated: 2024/06/26 09:49:00 by matde-ol         ###   ########.fr       */
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
	int i;

	i = 2;
	if (check_size(var->info.img_no.coord, &i) == false)
		return (-1);
	if (!(var->info.img_so.coord.x == var->info.img_so.coord.y
			&& var->info.img_so.coord.x == i)
			&& (var->info.img_ea.coord.x == var->info.img_ea.coord.y
			&& var->info.img_ea.coord.x == i)
			&& (var->info.img_we.coord.x == var->info.img_we.coord.y
			&& var->info.img_we.coord.x == i))
		return (-1);
	return (0);
}
