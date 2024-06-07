/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wmlx_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:07:21 by bedarenn          #+#    #+#             */
/*   Updated: 2024/06/07 15:39:09 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "cub3d.h"

bool	wmlx_key_update(t_joe_mama *var)
{
	static t_tv	last;
	t_tv		actu;
	t_ltime		diff;
	float		mv;

	gettimeofday(&actu, NULL);
	diff = diff_timeval(actu, last);
	if (diff < FMS)
		return (false);
	last = actu;
	mv = MV_SPEED / FPS * (diff / FMS);
	if (var->press.key_W)
		var->info.base.pos.y -= mv;
	if (var->press.key_A)
		var->info.base.pos.x -= mv;
	if (var->press.key_S)
		var->info.base.pos.y += mv;
	if (var->press.key_D)
		var->info.base.pos.x += mv;
	return (true);
}

int	wmlx_loop(t_joe_mama *var)
{
	if (wmlx_key_update(var))
	{
		wmlx_loop_draw(var);
		wmlx_update_win(var->mlx);
	}
	return (0);
}
