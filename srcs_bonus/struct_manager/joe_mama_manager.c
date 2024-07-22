/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   joe_mama_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 12:30:13 by bedarenn          #+#    #+#             */
/*   Updated: 2024/07/22 11:39:29 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./hdrs_bonus/cub3d.h"

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
