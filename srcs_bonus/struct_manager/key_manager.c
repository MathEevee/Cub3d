/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 12:28:18 by bedarenn          #+#    #+#             */
/*   Updated: 2024/07/09 17:31:04 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_key_press	key_press_init(void)
{
	t_key_press	press;

	press.key_w = false;
	press.key_a = false;
	press.key_s = false;
	press.key_d = false;
	press.key_left = false;
	press.key_right = false;
	return (press);
}
