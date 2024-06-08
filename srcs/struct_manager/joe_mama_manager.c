/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   joe_mama_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 12:30:13 by bedarenn          #+#    #+#             */
/*   Updated: 2024/06/06 13:01:57 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	joe_mama_init(t_joe_mama *var)
{
	var->mode = MODE_MINIMAP;
	var->press = key_press_init();
}
