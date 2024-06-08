/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 12:28:18 by bedarenn          #+#    #+#             */
/*   Updated: 2024/06/07 15:56:25 by bedarenn         ###   ########.fr       */
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
	return (press);
}
