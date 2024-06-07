/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 12:28:18 by bedarenn          #+#    #+#             */
/*   Updated: 2024/06/06 12:29:31 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_key_press	key_press_init(void)
{
	t_key_press	press;

	press.key_W = false;
	press.key_A = false;
	press.key_S = false;
	press.key_D = false;
	return (press);
}
