/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   joe_mama_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 12:30:13 by bedarenn          #+#    #+#             */
/*   Updated: 2024/07/23 15:20:04 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	joe_mama_init(t_joe_mama *var)
{
	var->press = key_press_init();
}

void	change_mode(t_pdata *data)
{
	t_data	*tmp;

	tmp = data->map;
	data->map = data->win;
	data->win = tmp;
}
